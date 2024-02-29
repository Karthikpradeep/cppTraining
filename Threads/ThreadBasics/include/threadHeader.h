#ifndef THREADHEADER_H
#define THREADHEADER_H

#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace chrono;

typedef unsigned long long ull;

class MyThread{
	private:
		ull OddSum;
		ull EvenSum;
	public:
		MyThread();
		~MyThread();

		void FindEven(ull start, ull end);
		void FindOdd(ull start, ull end);
		void display();
};
#endif
