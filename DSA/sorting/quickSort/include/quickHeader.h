#ifndef QUICKHEADER_H
#define QUICKHEADER_H

#include <bits/stdc++.h>

using namespace std;

class QuickSort{
	private:
		int pivot,i,j;
		int partition(vector<int> &arr,int low, int high);
		void qs(vector<int> &arr, int low, int high);
	public:
		QuickSort();
		~QuickSort();
		void quickSort(vector<int> &arr);
};
#endif

