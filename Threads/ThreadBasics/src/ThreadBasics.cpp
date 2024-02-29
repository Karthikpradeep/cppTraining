#include <threadHeader.h>

MyThread::MyThread():OddSum(0),EvenSum(0){
}

MyThread::~MyThread(){
}

void MyThread::FindEven(ull start,ull end){
	for(ull i = start; i<= end; ++i){
		if((i%2) == 0){
			EvenSum += i;
		}
	}
}

void MyThread::FindOdd(ull start,ull end){
	for(ull i = start; i<= end; ++i){
		if((i%2) != 0){
			OddSum += i;
		}
	}
}

void MyThread::display(){
	cout<<"OddSum - "<<OddSum<<endl;
	cout<<"EvenSum - "<<EvenSum<<endl;
}
