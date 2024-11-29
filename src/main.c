#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "http.h"
#include "log.h"

#define PORT 8080
#define MAX_CONNECTIONS 10


int main(int argc, char *argv[]) 
{
    // Print the server name with assci art.
    ascii_art("static/ascii/logo.txt");

    // Create a socket.
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) 
    {
        return 1;
    } 
     
    // Create an adress.
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket to an address.
    if (bind(socket_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) 
    {
        close(socket_fd);
        return 2;
    }

    // Listen for incoming connections.
    if (listen(socket_fd, MAX_CONNECTIONS) == -1) 
    {
        close(socket_fd);
        return 3;
    }

    // Accept incoming connections.
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);

    int client_fd;

    while (true) 
    {
        client_fd = accept(socket_fd, (struct sockaddr*)&client_addr, &client_len);
        if (client_fd == -1) 
        {
            close(socket_fd);
            return 4;
        }

        // Read the request.
        char buffer[MAX_REQUEST_LENGTH] = { 0 };
        int bytes_read = recv(client_fd, buffer, MAX_REQUEST_LENGTH - 1, 0);
        if (bytes_read <= -1) 
        {
            close(client_fd);
            continue;
        }

        // Parse the request.
        http_request *req = malloc(sizeof(http_request));
        if (req == NULL) 
        {
            close(client_fd);
            close(socket_fd);
            return 6;
        }

        parse_request(req, buffer);

        // Generate a http response.
        http_response *res = malloc(sizeof(http_response));
        if (res == NULL)
        {   
            free_request(req);
            close(client_fd);
            close(socket_fd);
            return 7;
        }

        // Validate the request TODO: Implement this function.
        if (!validate_request(req)) 
        {
            response(res, HTTP_BAD_REQUEST, "text/html", "<h1 style=\"color: red;\">400 Bad Request</h1>");
            send(client_fd, res->full_response, strlen(res->full_response), 0);
            free_request(req);
            free_response(res);
            continue;
        }

        // Handle GET requests for /.
        if (strcmp(req->method, HTTP_GET) == 0 && strcmp(req->path, "/") == 0) 
        {
            response(res, HTTP_OK, "text/html", "<h1 style=\"color: blue;\">This is the home page!</h1>");
        }
        else 
        {
            response(res, HTTP_NOT_FOUND, "text/html", "<h1 style=\"color: red;\">404 Not Found</h1>");
        }

        send(client_fd, res->full_response, strlen(res->full_response), 0);
        log_stdout(req, res);

        free_request(req);
        free_response(res);
    }

    
    close(client_fd);
    close(socket_fd);

    return 0;
}


