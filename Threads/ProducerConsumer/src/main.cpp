#include <PCheader.h>

int main(){
	ProducerConsumer pc;

	thread t1(&ProducerConsumer::producer,&pc,100);
	thread t2(&ProducerConsumer::consumer,&pc);
	t1.join();
	t2.join();

	return 0;
}
