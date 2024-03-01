#ifndef SUMHEADER_H
#define SUMHEADER_H

#include <iostream>

using namespace std;

class OddEvenSum{
	private:
		int OddSum;
		int EvenSum;
	public:
		OddEvenSum();
		~OddEvenSum();
		void FindEven();
		void FindOdd();
		void Display();
};
#endif
