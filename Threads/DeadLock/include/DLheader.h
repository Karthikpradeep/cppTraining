#ifndef DLHEADER_H
#define DLHEADER_H

#include <iostream>
#include <thread>
#include <mutex>
#include <unistd.h>

using namespace std;

class DeadLock{
	private:
		mutex m1;
		mutex m2;

	public:
		DeadLock();
		~DeadLock();
		void thread1();
		void thread2();
};
#endif
