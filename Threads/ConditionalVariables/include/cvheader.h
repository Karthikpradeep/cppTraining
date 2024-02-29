#ifndef CVHEADER_H
#define CVHEADER_H

#include <iostream>
#include <thread>
#include <mutex>
#include <unistd.h>
#include <condition_variable>

using namespace std;

class CV{
	private:
		condition_variable cv;
		mutex m;
		long balance;
		int money;
	public:
		CV();
		~CV();
		void addMoney(int money);
		void withdrawMoney(int money);
};
#endif
