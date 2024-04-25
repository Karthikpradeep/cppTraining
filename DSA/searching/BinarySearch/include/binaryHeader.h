#ifndef BINARYHEADER_H
#define BINARYHEADER_H

#include <iostream>
#include <algorithm>

using namespace std;

class BinarySearch{
	private:
		int* arr;
		int left;
		int right;
		int middle;
		bool found;

	public:
		BinarySearch();
		~BinarySearch();
		void addElement(int size);
		void search(int size, int element);
};
#endif

