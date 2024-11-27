#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include <sys/socket.h>
#include <netinet/in.h>


#define PORT 8080
#define MAX_CONNECTIONS 10


int main(int argc, char *argv[]) {

    // Create a socket.
    int socket_fd = socket(PF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        return 1;
    } 
     
    // Create an adress.
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket to an address.
    if (bind(socket_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        close(socket_fd);
        return 2;
    }

    // Listen for incoming connections.
    if (listen(socket_fd, MAX_CONNECTIONS) == -1) {
        close(socket_fd);
        return 3;
    }

    // Accept incoming connections.
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);

    int client_fd = accept(socket_fd, (struct sockaddr*)&client_addr, &client_len);
    if (client_fd == -1) {
        close(socket_fd);
        return 4;
    }

    // Send a message to the client.
    const char *response = "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\nContent-Length: 12\r\n\r\nHello World!";
    send(client_fd, response, strlen(response), 0);

    close(socket_fd);

    return 0;
}


