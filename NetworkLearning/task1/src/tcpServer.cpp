#include<common.h>

using namespace std;

int main(){
	
	int serverSocket = socket(AF_INET,SOCK_STREAM,0);
	if(serverSocket == -1){
		cerr<<"!!! Error occured while creating the server socket !!!"<<endl;
		exit(EXIT_FAILURE);
	}

	sockaddr_in serverAddress;
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_addr.s_addr = INADDR_ANY;
	serverAddress.sin_port = htons(8888);
	if(bind(serverSocket,(sockaddr*)&serverAddress,sizeof(serverAddress)) == -1){
		cerr<<"!!! Error while assigning address to the socket !!!"<<endl;
		close(serverSocket);
		exit(EXIT_FAILURE);
	}

	if(listen(serverSocket,6) == -1){
		cerr<<"!!! Error while listening for connection !!!"<<endl;
		close(serverSocket);
		exit(EXIT_FAILURE);
	}

	cout<<"......Server listening to port 8888......."<<endl;
                sockaddr_in clientAddress;
                socklen_t clientAddSize = sizeof(clientAddress);
                int clientSocket = accept(serverSocket,(sockaddr*)&clientAddress,&clientAddSize);

                if(clientSocket == -1){
                        cerr<<"!!! Error while accepting the client connection !!!"<<endl;
                        close(serverSocket);
                        exit(EXIT_FAILURE);
                }
                cout<<"......Connection established with the client......"<<endl;


	while(true){
		char buffer[1024];
		ssize_t byteRead = recv(clientSocket,buffer,sizeof(buffer),0);
		if(byteRead == -1){
			cerr<<"!!! Error while receiving data from client !!!"<<endl;
			close(serverSocket);
			exit(EXIT_FAILURE);
		}
		else{
			buffer[byteRead] = '\0';
			cout<<"Message from client - "<<buffer<<endl;

			//sending response form server to client 
			const int bufferSize = 1024;
			char response[bufferSize];
			cout<<"Enter response to client - ";
			cin.getline(response,bufferSize);
			if(strcmp(response,"bye") == 0){
				cout<<"Server exiting"<<endl;
				send(clientSocket,response,strlen(response),0);
				close(clientSocket);
				exit(EXIT_SUCCESS);
			}
			else{
				ssize_t bytesSent = send(clientSocket,response,strlen(response),0);
				if(bytesSent == -1 || bytesSent<strlen(response)){
                                	cerr<<"!!! Error while sending message to the client !!!"<<endl;
                        	}

			}
		}
	}
	close(clientSocket);
	close(serverSocket);
}

