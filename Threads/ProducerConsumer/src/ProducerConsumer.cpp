#include <PCheader.h>

ProducerConsumer::ProducerConsumer():maxBufferSize(50){
}

ProducerConsumer::~ProducerConsumer(){
}


void ProducerConsumer::producer(int val){
	while(val){
		unique_lock<mutex> locker(m);
		cond.wait(locker ,[this]() {return buffer.size() < maxBufferSize;});
		buffer.push_back(val);
		cout<<"Produced - "<<val<<endl;
		val--;

		locker.unlock();
		cond.notify_one();
	}
	
}

void ProducerConsumer::consumer(){
	while(true){
		unique_lock<mutex> locker(m);
		cond.wait(locker,[this]() {return buffer.size() > 0;});
		int val = buffer.back();
		buffer.pop_back();
		cout<<"Consumed - "<<val<<endl;
		locker.unlock();
		cond.notify_one();
		if(val == 1){
			cond.notify_one();
			break;
		}
	}
}
