#include "mergeHeader.h"

MergeSorting::MergeSorting(){
	left = 0;
	right = 0;
}

MergeSorting::~MergeSorting(){
}

void MergeSorting::merge(vector<int> &arr,int low,int mid,int high){
	vector<int> temp;
	left = low;
	right = mid+1;
	
	while( left <= mid && right <= high){
		if(arr[left] <= arr[right]){
			temp.push_back(arr[left]);
			left++;
		}
		else{
			temp.push_back(arr[right]);
			right++;
		}
	}
	while(left <= mid){
		temp.push_back(arr[left]);
		left++;
	}

	while(right <= high){
		temp.push_back(arr[right]);
		right++;
	}

	for(int i=low; i<= high ;i++){
		arr[i] = temp[i-low];
	}
}

	

void MergeSorting::mergeSort(vector<int> &arr,int low,int high){
	if(low>=high)return;
	int mid = (low+high)/2;
	mergeSort(arr,low,mid);
	mergeSort(arr,mid+1,high);
	merge(arr,low,mid,high);
}

void MergeSorting::sortArray(vector<int> &arr){
	mergeSort(arr,0,arr.size()-1);
}
