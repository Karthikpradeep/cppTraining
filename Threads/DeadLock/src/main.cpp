#include <DLheader.h>

int main(void){
	DeadLock dl;

	thread t1(&DeadLock::thread1,&dl);
	thread t2(&DeadLock::thread2,&dl);

	t1.join();
	t2.join();
}
