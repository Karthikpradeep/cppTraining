#include <iostream>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int client_socket;
    struct sockaddr_in server_address;
    char buffer[BUFFER_SIZE] = {0};

    // Creating socket
    if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Server configuration
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        exit(EXIT_FAILURE);
    }

    // Connecting to the server
    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    fd_set rset;
    // Reading and writing data to/from the server
    char str[1024]; // user name
    std::cout << "Enter your name: ";
    std::cin >> str;
    strcat(str, "> ");
    char strname[1024] ;

    // Send the user name to the server
   // send(client_socket, str, strlen(str), 0);

    while (1) {
        FD_ZERO(&rset);
        FD_SET(0, &rset); // Add stdin (user input) to the set
        FD_SET(client_socket, &rset); // Add the client socket to the set

        select(client_socket + 1, &rset, NULL, NULL, NULL);

        if (FD_ISSET(0, &rset)) {
            // User input is ready
            fgets(buffer, BUFFER_SIZE, stdin);
            // Send user name along with the data to the server
            memset(strname , 0 , BUFFER_SIZE);
            strcat(strname , str);
            buffer[strcspn(buffer, "\n")] = 0;
            if(strlen(buffer) != 0){
            	strcat(strname, buffer);//bug fix
            	send(client_socket, strname, strlen(strname), 0);
            }	
        }

        if (FD_ISSET(client_socket, &rset)) {
            // Data from the server is ready
            memset(buffer, 0, BUFFER_SIZE);
            // Handle data received from the server
            if (read(client_socket, buffer, BUFFER_SIZE) <= 0) {
                // Handle disconnection or error
                std::cerr << "Server disconnected or error occurred." << std::endl;
                break;
            }
            buffer[strcspn(buffer, "\n")] = 0;
            std::cout << buffer << std::endl;
        }
    }

    close(client_socket);
    return 0;
}

