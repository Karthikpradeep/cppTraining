#ifndef TWOHEADER_H
#define TWOHEADER_H

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class TwoPointer{
	private:

		int left;
		int right;
		int maxWater;
		int minHeight;
		vector<int> height;

	public:
		TwoPointer();
		~TwoPointer();
		int mostWater();
		void addHeight(int val);
};
#endif
