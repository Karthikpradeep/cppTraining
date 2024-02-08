#include <headers.h>

using namespace std;

const int MAX_CLIENTS = 10;
const int BUFFER_SIZE = 1024;

int main() {
    // Creating a server socket
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        perror("!!! Error while creating a server socket !!!");
        exit(EXIT_FAILURE);
    }

    // Initialize server structure address
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(8888);

    // Binding the server socket to the specified address and port
    if (bind(serverSocket, (sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {
        perror("!!! Binding Failed !!!");
        exit(EXIT_FAILURE);
    }

    // Listening to the port number
    if (listen(serverSocket, MAX_CLIENTS) == -1) {
        perror("!!! Listen failed !!!");
        exit(EXIT_FAILURE);
    }

    cout << "......Server listening to the port 8888......" << endl;

    // Managing set of file descriptors
    int clientSockets[MAX_CLIENTS] = {0};
    char buffer[BUFFER_SIZE] = {0}; // buffer to storing data that is sent or received
    fd_set masterSet; // To store all FD that the server is interested to monitor
    FD_ZERO(&masterSet); // Clears all FD from masterSet set
    FD_SET(serverSocket, &masterSet); // Adds server socket to FD set
    int maxFd = serverSocket;

    while (true) {
        fd_set readSet = masterSet; // For temporary storage of FD's
        // Waiting for activity on any socket
        if (select(maxFd + 1, &readSet, nullptr, nullptr, nullptr) < 0) {	//select function call monitor multiple FD's,(nfds,set of fd's for monitor for read activities
            perror("!!! Select failed !!!");
            exit(EXIT_FAILURE);
        }

        // Check for activity on serverSocket (new connection)
        if (FD_ISSET(serverSocket, &readSet)) {	//check if server socket is in readset
            sockaddr_in clientAddress;
            socklen_t clientSize = sizeof(clientAddress);
            int clientSocket = accept(serverSocket, (sockaddr*)&clientAddress, &clientSize);	//accepting new incoming connection on server socket and store the FD as clientSocket
            if (clientSocket == -1) {
                perror("!!! Error while accepting connection !!!");
                exit(EXIT_FAILURE);
            }

            // Add a new client to the array clientSockets
            for (int i = 0; i < MAX_CLIENTS; ++i) {
                if (clientSockets[i] == 0) {
                    clientSockets[i] = clientSocket;// when empty socket is found new client socket is stored in the slot
                    FD_SET(clientSocket, &masterSet);//new client is added to the masterSet indicating that it should be monitored for read activity
                    if (clientSocket > maxFd) {// updating maxFd
                        maxFd = clientSocket;
                    }
                    break;
                }
            }
            cout << "......New Client Connected......" << endl;
        }

        // Check for activities in the client side
        for (int i = 0; i < MAX_CLIENTS; ++i) {
            if (clientSockets[i] > 0 && FD_ISSET(clientSockets[i], &readSet)) {	//check if there is data to be read from that client
                memset(buffer, 0, BUFFER_SIZE);// clear the buffer 

                // Receive data from the client
                ssize_t bytesRead = read(clientSockets[i], buffer, BUFFER_SIZE);//reads data from client socket to buffer
                if (bytesRead <= 0) {
                    // Handle disconnection or error
                    cout << "......Client disconnected......" << endl;
                    close(clientSockets[i]);
                    FD_CLR(clientSockets[i], &masterSet);//client socket is cleared from masterSet
                    clientSockets[i] = 0;
                } else {
                    // Broadcast the received data to all other clients
                    for (int j = 0; j < MAX_CLIENTS; ++j) {
                        if (clientSockets[j] > 0 && clientSockets[j] != clientSockets[i]) {//check current client socket is valid and not same as the client socket (data received)
                            send(clientSockets[j], buffer, static_cast<size_t>(bytesRead), 0);//send data to other clients
                        }
                    }
                }
            }
        }
    }
    close(serverSocket);
    return 0;
}

