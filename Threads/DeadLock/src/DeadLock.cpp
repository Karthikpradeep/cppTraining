#include <DLheader.h>

DeadLock::DeadLock(){
}

DeadLock::~DeadLock(){
}

void DeadLock::thread1(){
	m1.lock();
	//sleep(1);
	m2.lock();
	cout<<"Critical section of thread 1"<<endl;
	m2.unlock();
	m1.unlock();
}

void DeadLock::thread2(){
	m2.lock();
	//sleep(1);
	m1.lock();
	cout<<"Critcal section of thread 2 "<<endl;
	m1.unlock();
	m2.unlock();
}
