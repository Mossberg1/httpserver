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
    log_logo("static/ascii/logo.txt");

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

        http_response *res = malloc(sizeof(http_response));
        if (res == NULL)
        {   
            close(client_fd);
            close(socket_fd);
            return 5;
        }

        response(res, 200, "text/plain", "Hello, World! My name is William Mossberg, and this is my first web server in C.");

        send(client_fd, res->full_response, strlen(res->full_response), 0);
        free_response(res);
    }

    
    close(client_fd);
    close(socket_fd);

    return 0;
}


