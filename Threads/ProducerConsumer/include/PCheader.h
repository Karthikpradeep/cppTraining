#ifndef PCHEADER_H
#define PCHEADER_H

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <deque>

using namespace std;

class ProducerConsumer{
	private:
		mutex m;
		condition_variable cond;
		deque<int> buffer;
		const unsigned int maxBufferSize;
		int val;
	public:
		ProducerConsumer();
		~ProducerConsumer();
		void producer(int val);
		void consumer();
};
#endif
