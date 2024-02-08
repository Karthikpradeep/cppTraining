#include<iostream>
#include<unistd.h>

using namespace std;

int main(){
	
	pid_t pid = fork();

	if(pid<0){
		cerr<<"!!! Error occured !!!"<<endl;
		return 1;
	}
	else if(pid == 0){
		cout<<"Process id of the child process - "<<getpid()<<endl;
	}
	else{
		cout<<"Process id of the parent process - "<<getpid()<<endl;
	}


	return 0;
}
