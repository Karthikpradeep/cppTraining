#include <quickHeader.h>

QuickSort::QuickSort(){
	pivot = 0;
	i=0;
	j=0;
}

QuickSort::~QuickSort(){
}

int QuickSort::partition(vector<int> &arr, int low, int high){
	pivot = arr[low];
	i = low;
	j = high;

	while(i<j){
		while(arr[i] <= pivot && i <= high-1){
			i++;
		}
		while(arr[j] >= pivot && j>= low+1 ){
			j--;
		}
		if(i<j){
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[low],arr[j]);
	return j;
}

void QuickSort::qs(vector<int> &arr, int low, int high){
	if(low<high){
		int pIndex = partition(arr,low,high);
		qs(arr,low,pIndex-1);
		qs(arr,pIndex+1,high);
	}
}

void QuickSort::quickSort(vector<int> &arr){
	qs(arr,0,arr.size()-1);
}

