#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <signal.h>
#include <fcntl.h>
#include <errno.h>

#include "include/http.h"
#include "include/log.h"

#define PORT 8080
#define MAX_CONNECTIONS 10

volatile sig_atomic_t stop;

void signal_handler(int signum) {
    stop = 1;
}


int main(int argc, char *argv[]) {
    signal(SIGINT, signal_handler);

    // Print the server name with assci art.
    ascii_art("../static/ascii/logo");

    // Create a socket.
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        perror("Could not create socket.\n");
        return 1;
    }

    // Set the socket to non-blocking.c
    int flags = fcntl(socket_fd, F_GETFL, 0);
    fcntl(socket_fd, F_SETFL, flags | O_NONBLOCK);

    // Create an adress.
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket to an address.
    if (bind(socket_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("Could not bind socket.\n");
        close(socket_fd);
        return 2;
    }

    // Listen for incoming connections.
    if (listen(socket_fd, MAX_CONNECTIONS) == -1) {
        perror("Could not listen for incoming connections.\n");
        close(socket_fd);
        return 3;
    }

    // Accept incoming connections.
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);

    int client_fd;

    while (!stop) {
        client_fd = accept(socket_fd, (struct sockaddr *) &client_addr, &client_len);
        if (client_fd == -1) {
            if (errno == EWOULDBLOCK) {
                usleep(10000);
                continue;
            }
            perror("Could not accept incoming connection.\n");
            close(socket_fd);
            return 4;
        }

        // Read the request.
        char buffer[MAX_REQUEST_LENGTH] = {0};
        ssize_t bytes_read = recv(client_fd, buffer, MAX_REQUEST_LENGTH - 1, 0);
        if (bytes_read <= -1) {
            perror("Could not read request.\n");
            close(client_fd);
            continue;
        }

        // Parse the request.
        http_request *req = malloc(sizeof(http_request));
        if (req == NULL) {
            perror("Memory allocation failed.\n");
            close(client_fd);
            close(socket_fd);
            return 6;
        }

        init_request(req);

        parse_request(req, buffer);

        // Generate a http response.
        http_response *res = malloc(sizeof(http_response));
        if (res == NULL) {
            perror("Memory allocation failed.\n");
            free_request(req);
            close(client_fd);
            close(socket_fd);
            return 7;
        }

        // Validate the request TODO: Implement this function.
        if (!validate_request(req)) {
            perror("Request validation failed.\n");
            generate_response(res, HTTP_BAD_REQUEST, "text/html", "<h1 style=\"color: red;\">400 Bad Request</h1>");
            send(client_fd, res->full_response, strlen(res->full_response), 0);
            free_request(req);
            free_response(res);
            continue;
        }

        // Handle requests for /.
        if (strcmp(req->method, HTTP_GET) == 0 && strcmp(req->path, "/") == 0) {
            generate_response(res, HTTP_OK, "application/json", "{\"message\": \"Hello, World! Sucessful GET request\"}");
        } else if (strcmp(req->method, HTTP_POST) == 0 && strcmp(req->path, "/") == 0) {
            generate_response(res, HTTP_OK, "application/json", "{\"message\": \"Hello, World! Sucessful POST request.\"}");
        } else {
            generate_response(res, HTTP_BAD_REQUEST, "application/json", "{\"message\": \"Request method not supported.\"}");
        }

        send(client_fd, res->full_response, strlen(res->full_response), 0);

        // FIXME: Remove this.
        printf("BODY:\t\n %s\n", req->body);

        log_stdout(req, res);

        free_request(req);
        free_response(res);
    }

    printf("\nClosing server...\n");

    close(client_fd);
    close(socket_fd);

    return 0;
}
