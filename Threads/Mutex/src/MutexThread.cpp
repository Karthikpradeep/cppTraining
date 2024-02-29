#include <header.h>

MutexThread::MutexThread():myAmount(0){
}

MutexThread::~MutexThread(){
}

void MutexThread::addMoney(){
	m.lock();
	for(int i = 1;i<=100000;++i){
		++myAmount;
	}
	m.unlock();

}

void MutexThread::display(){
	cout<<"Amount - "<<myAmount<<endl;
}
