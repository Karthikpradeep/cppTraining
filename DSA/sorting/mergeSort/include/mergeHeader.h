#ifndef MERGEHEADER_H
#define MERGEHEADER_H

#include <iostream>
#include <vector>

using namespace std;

class MergeSorting{
	private:
		int left,right;
		void merge(vector<int> &arr, int low, int mid, int high);
		void mergeSort(vector<int> &arr, int low, int high);
	public:
		MergeSorting();
		~MergeSorting();
		void sortArray(vector<int> &arr);
};
#endif

