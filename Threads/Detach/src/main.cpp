#include <detachHeader.h>

int main(void){
	DetachThread myThread(10);
	cout<<"main() before"<<endl;
	thread t1(&DetachThread::execute, &myThread);

	t1.detach();
	cout<<"main() after"<<endl;
	
}
