#include <errno.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>


#include "../include/http.h"
#include "../include/log.h"
#include "../include/parser.h"


#define BUFSIZE 1024
#define PORT 8080


int main(int argc, char* argv[]) 
{
        welcome();

        // Create a socket.
        int sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0) {
                printf("Socket: %s\n", strerror(errno));
                return 1;
        }

        struct sockaddr_in addr;

        addr.sin_family      = AF_INET;
        addr.sin_addr.s_addr = INADDR_ANY;
        addr.sin_port        = htons(PORT); 

        // Bind the socket.
        if (bind(sockfd, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
                close(sockfd);
                printf("Bind: %s\n", strerror(errno));
                return 2;
        }

        // Listen for connection
        if (listen(sockfd, 3) < 0) {
                close(sockfd);
                printf("Listen: %s\n", strerror(errno));
                return 3;
        }

        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);

        // Accept the connection
        int client_fd = accept(sockfd, (struct sockaddr*)&client_addr, &client_len);
        if (client_fd < 0) {
                close(sockfd);
                printf("Accept: %s\n", strerror(errno));
                return 4;
        }

        char buffer[BUFSIZE];

        // Read the request.
        ssize_t n_read = read(client_fd, buffer, sizeof(buffer) - 1);
        if (n_read < 0) {
                close(sockfd);
                printf("Read: %s\n", strerror(errno));
                return 5;
        }

        printf("BUFFER:\n%s\n\n", buffer);

        http_request* req = (http_request*)malloc(sizeof(http_request));
        if (req == NULL) {
                close(sockfd);
                printf("Malloc failed!\n");
                return 6;
        }

        if (parse_request(buffer, sizeof(buffer), req) < 0) {
                free(req);
                close(sockfd);
                printf("Failed to parse http request.\n");
                return 7;
        } 

        char* msg = "Hello, World!";
        
        // Send a response.
        if (send(client_fd, msg, strlen(msg), 0) < 0) {
                free(req);
                close(sockfd);
                printf("Send: %s\n", strerror(errno));
                return 8;
        }

        free(req);
        close(sockfd);

        return 0;
}
