#ifndef DETACHHEADER_H
#define DETACHHEADER_H

#include <iostream>
#include <thread>
#include <unistd.h>

using namespace std;

class DetachThread{
	private:
		int count;
		thread t1;
	public:
		DetachThread(int count);
		~DetachThread();
		void execute();
};
#endif

