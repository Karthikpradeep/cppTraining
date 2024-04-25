#include <binaryHeader.h>

BinarySearch::BinarySearch(){
	left = 0;
	right = 0;
	middle = 0;
	found = false;
}

BinarySearch::~BinarySearch(){
	delete[] arr;
}

void BinarySearch::addElement(int size){
	arr = new int[size];
	cout<<"Enter the elements to the array - ";
	for(int i=0;i<size;++i){
		cin>>arr[i];
	}
}

void BinarySearch::search(int size, int element){
	right = size-1;
	sort(arr,arr+size);
	while(left<=right){
		middle = left+(right - left)/2;

		if( arr[middle] == element){
			found = true;
			break;
		}
		if(arr[middle] < element){
			left = middle + 1;
		}
		else{
			right = middle - 1;
		}
	}
	if(found){
		cout<<"Element "<<element<<" found at index - "<<middle<<endl;
	}
	else{
		cout<<"Element "<<element<<" not found"<<endl;
	}
}	
