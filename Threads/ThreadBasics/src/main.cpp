#include <threadHeader.h>

int main(void){
	ull start = 0,end = 990000000;

	auto startTime = high_resolution_clock::now();

	MyThread myThread;

	//myThread.FindEven(start,end);
	//myThread.FindOdd(start,end);
	thread t1(&MyThread::FindEven,&myThread,start,end);
	thread t2(&MyThread::FindOdd,&myThread,start,end);

	t1.join();
	t2.join();

	auto stopTime = high_resolution_clock::now();
   	auto duration = duration_cast<microseconds>(stopTime - startTime);
	
	myThread.display();
	cout << "Time taken in sec - " << duration.count() / 1000000 << endl;
}
