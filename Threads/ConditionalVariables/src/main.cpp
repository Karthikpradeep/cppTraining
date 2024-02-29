#include <cvheader.h>

int main(void){
	CV CondVar;

	thread t1(&CV::withdrawMoney,&CondVar,500);
	sleep(5);
	thread t2(&CV::addMoney,&CondVar,500);
	t1.join();
	t2.join();
}
