#include "mergeHeader.h"

int main(){
	MergeSorting ms;
	int size,element;
	vector<int> arr;
	cout<<"Enter the number of elements needed - ";
	cin>>size;
	cout<<"Enter the elements - ";
	for(int i=0;i<size;i++){
		cin>>element;
		arr.push_back(element);
	}
	cout<<"Array before sorting - ";
	for(int val:arr){
		cout<<val<<" ";
	}
	ms.sortArray(arr);
	cout<<"\nArray after sorting - ";
	for(int val:arr){
		cout<<val<<" ";
	}
	cout<<endl;
	return 0;
}


