#include <iostream>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

struct Client {
    int socket;
    std::string name;
};

int main() {
    int server_socket, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    int client_sockets[MAX_CLIENTS] = {0};
    fd_set all_fds, read_fds;

    // Creating socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Server configuration
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Binding the socket to the specified address and port
    if (bind(server_socket, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listening for incoming connections
    if (listen(server_socket, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    std::cout << "Server listening on port " << PORT << std::endl;

    FD_ZERO(&all_fds);
    FD_SET(server_socket, &all_fds);

    while (1) {
        read_fds = all_fds;

        // Waiting for activity on any socket
        if (select(FD_SETSIZE, &read_fds, NULL, NULL, NULL) < 0) {
            perror("Select failed");
            exit(EXIT_FAILURE);
        }

        // Check for activity on the server socket (new connection)
        if (FD_ISSET(server_socket, &read_fds)) {
            if ((new_socket = accept(server_socket, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
                perror("Accept failed");
                exit(EXIT_FAILURE);
            }

            // Add the new client socket to the array
            for (int i = 0; i < MAX_CLIENTS; ++i) {
                if (client_sockets[i] == 0) {
                    client_sockets[i] = new_socket;
                    FD_SET(new_socket, &all_fds);
                    break;
                }
            }

            std::cout << "New client connected." << std::endl;
        }

        // Check for activity on client sockets
        for (int i = 0; i < MAX_CLIENTS; ++i) {
            if (client_sockets[i] > 0 && FD_ISSET(client_sockets[i], &read_fds)) {
                memset(buffer, 0, BUFFER_SIZE);

                // Receive data from the client
                if (read(client_sockets[i], buffer, BUFFER_SIZE) <= 0) {
                    // Handle disconnection or error
                    std::cout << "Client disconnected." << std::endl;
                    close(client_sockets[i]);
                    FD_CLR(client_sockets[i], &all_fds);
                    client_sockets[i] = 0;
                } else {
                    // Broadcast the received data to all other clients
                    for (int j = 0; j < MAX_CLIENTS; ++j) {
                        if (client_sockets[j] > 0 && client_sockets[j] != client_sockets[i]) {
                            send(client_sockets[j], buffer, strlen(buffer), 0);
                        }
                    }
                }
            }
        }
    }

    close(server_socket);
    return 0;
}

