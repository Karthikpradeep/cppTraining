#include <header.h>

int main(void){
	UniqueLock uLock;
	thread t1(&UniqueLock::task,&uLock,"t1",10);
	thread t2(&UniqueLock::task,&uLock,"t2",5);
	t1.join();
	t2.join();
}
