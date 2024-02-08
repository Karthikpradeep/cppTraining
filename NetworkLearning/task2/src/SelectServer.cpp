#+include<iostream>
#include<vector>
#include<cstring>
#include<unistd.h>
#include<arpa/inet.h>

using namespace std;

int main(){

	//create a server socket

	int serverSocket = socket(AF_INET,SOCK_STREAM,0);	//domain,type,protocol , It returns a file descriptor
	if(serverSocket == -1){
		cerr<<"!!! Error while creating a socket in server side !!!"<<endl;
		exit(EXIT_FAILURE);
	}

	//Intitialize server address struct

	sockaddr_in ServerAddress;
	ServerAddress.sin_family = AF_INET;
	ServerAddress.sin_add.s_addr = INADDR_ANY;
	ServerAddress.sin_port = htons(8888);

	//binding the socket

	if(bind(serverSocket,(sockaddr*)&ServerAddress,sizeof(ServerAddress)) == -1){
		cerr<<"!!! Error while assigning address to serverSocket !!!"<<endl;
		close(serverSocket);
		exit(EXIT_FAILURE);
	}

	//Listening for the incoming connection

	if(listen(serverSocket,10) == -1){
		cerr<<"!!! Error while listening to client connection !!!"<<endl;
		close(serverSocket);
		exit(EXIT_FAILURE);
	}
	cout<<"......Server is listening to the port 8888......"<<endl;

	//initilize neccessary data structures for managing multiple client connection in a server
	vector<int> clientSockets;//stores the file descriptors of the clients. Each time a client is connected its socket description is stor	      ed. When client disconnects the socket description is removed.
	fd_set masterSet;//fd_set is a data structure used by select represent set of FD. masterset used to keep track of all FD monitored by 				server
	FD_ZERO(&masterset);	//This function initializes the file descriptor set to contain no file descriptors.
	FD_SET(serverSocket,&masterset);// add serverSocket to masterset. serverSocket listen to the incoming client connection
	int maxFd = serverSocket;//maxFd is initialized with values of serverSocket file descriptor.
	// This determine the upper bound of the file descriptor checked by select. It is updated dynamically as new client connections are ac		accepted to keep track of the highest number of file descriptor.

	while(true){
		fd_set readSet = masterSet;//copy of masterSet which contain all file descriptors being monitored. select will modify the fd_set passed to it so org future use
		//select function is called to monitor the file descriptor for any activities.(readiness for this case)

		if(select(maxFd+1,&readSet,nullptr,nullptr,nullptr) == -1){//maxFd+1 -> max number of FD, readset -> set of file descriptor to monitor for read activity, 
			//other null pointer are used for monitoring write and error conditions and  for specifying time out duration

			cerr<<"!!! Error in select !!!"<<endl;
			close(serverSocket);
			exit(EXIT_FAILURE);
		}

		//	Checking for incoming connections on server socket

		if(FD_ISSET(serverSocket,&readSet){//checks if the server socket is set in the readset that indicates an incoming connection on the server socket
				sockaddr_in clientAddress;//to store client address information
				socklen_t clientSize = sizeof(clientAddress);//intitialize client size
				int clientSocket = accept(serverSocket,(sockaddr*)&clientAddress, &clientSize);//accept the incoming connection on server socket
				if(clientSocket == -1){
				cerr<<"!!! Error while accepting client connection !!!"<<endl;
				}
				else{
				cout<<"New connection from "<<inet_ntoa(clientAddress.sin_addr)<<" on socket "<<clientSocket<<endl;//prints information about the newly 						// established connection including ip address of client and client socket
				clientSockets.push_back(clientSocket);//add clientsocket to the vector to keep track
				FD_SET(clientSocket,&masterSet);//adds client socket to masterset
				maxFd = max(maxFd,clientSocket);// update maxFd to ensure new client socket is in range of FD to be monitored
				}
				}
				for (int i = 0; i < clientSockets.size(); ++i) {
				int clientSocket = clientSockets[i];
				if (FD_ISSET(clientSocket, &readSet)) {
				char buffer[BUFFER_SIZE];
				memset(buffer, 0, BUFFER_SIZE);

				// Receive data from the client
				ssize_t bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0);
				if (bytesRead <= 0) {
					if (bytesRead == 0) {
						cout << "Client on socket " << clientSocket << " disconnected." << endl;
					} else {
						cerr << "Error receiving data from client on socket " << clientSocket << endl;
					}

					close(clientSocket);
					FD_CLR(clientSocket, &masterSet);
					clientSockets.erase(clientSockets.begin() + i);
					--i;
				} else {
					// Broadcast the received data to all other clients
					for (int j = 0; j < clientSockets.size(); ++j) {
						int otherClientSocket = clientSockets[j];
						if (otherClientSocket != clientSocket) {
							ssize_t bytesSent = send(otherClientSocket, buffer, bytesRead, 0);
							if (bytesSent == -1 || bytesSent < bytesRead) {
								cerr << "Error sending message to client on socket " << otherClientSocket << endl;
							}
						}
					}
				}
			}
		}
	}
}


