#include <threadheader.h>

MyThread::MyThread(int count):count(count){
}

MyThread::~MyThread(){
}

void MyThread::execute(){
	while(count --> 0){
		cout<<count<<endl;
	}
	sleep(5);
}
