#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

class MutexThread{
	private:
		int myAmount;
		mutex m;
	public:
		MutexThread();
		~MutexThread();
		void addMoney();
		void display();
};
#endif




