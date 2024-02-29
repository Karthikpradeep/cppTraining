#ifndef THREADHEADER_H
#define THREADHEADER_H

#include <iostream>
#include <unistd.h>
#include <thread>

using namespace std;

class MyThread{
	private:
		int count;
		thread t1;
	public:
		MyThread(int count);
		~MyThread();
		void execute();
};
#endif

