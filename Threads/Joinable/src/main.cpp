#include <threadheader.h>

int main(void){
	MyThread myThread(10);
	cout<<"main function before "<<endl;
	thread t1(&MyThread::execute, &myThread);
	
	t1.join();
	//t1.join();
	if(t1.joinable()){
		t1.join();
	}

	cout<<"main function after "<<endl;
	
}	
