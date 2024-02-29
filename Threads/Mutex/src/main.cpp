#include <header.h>

int main(void){
	MutexThread myMutex;

	thread t1(&MutexThread::addMoney,&myMutex);
	thread t2(&MutexThread::addMoney,&myMutex);
	t1.join();
	t2.join();

	myMutex.display();

}
