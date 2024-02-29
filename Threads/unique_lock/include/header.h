#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

class UniqueLock{
	private:
		mutex m;
		int buffer;
	public:
		UniqueLock();
		~UniqueLock();
		void task(const char* threadNumber, int loopfor);

};
#endif
