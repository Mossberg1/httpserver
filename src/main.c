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
#include "../include/file.h"


#define BUFSIZE 1024
#define PORT 8080


int main(int argc, char* argv[]) 
{
        welcome();

        // Generate filetree data structure.
        struct fnode* root = fnode_create("/home/mossberg/repos/httpserver/static", NULL, true);
        struct fnode* vdir = fnode_create("videos", root, true);
        struct fnode* idir = fnode_create("images", root, true);

        fnode_add_child(root, vdir);
        struct fnode* the_land_of_the_lost = fnode_create("the-land-of-the-lost.mp4", vdir, false);
        struct fnode* the_ring = fnode_create("the-ring.mp4", vdir, false);
        fnode_add_child(vdir, the_land_of_the_lost);
        fnode_add_child(vdir, the_ring);
        
        fnode_add_child(root, idir);
        struct fnode* stitch = fnode_create("stitch.png", idir, false);
        struct fnode* creeper = fnode_create("creeper.png", idir, false);
        fnode_add_child(idir, stitch);
        fnode_add_child(idir, creeper);

        fnode_print(root, 0);

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
        free(creeper);
        free(stitch);
        free(idir);
        free(the_land_of_the_lost);
        free(the_ring);
        free(vdir);
        free(root);
        close(sockfd);

        return 0;
}
