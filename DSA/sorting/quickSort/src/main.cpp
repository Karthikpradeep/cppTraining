#include <quickHeader.h>

int main(){
	QuickSort QS;
	int size,element;
	vector<int> arr;
	cout<<"Enter the number of elements - ";
	cin>>size;

	cout<<"Enter the elements to the array - ";
	for(int i=0;i<size;i++){
		cin>>element;
		arr.push_back(element);
	}
	cout<<"Elements before sorting - ";
	for(int val : arr){
		cout<<val<<" ";
	}
	cout<<"\nElements after sorting - ";
	QS.quickSort(arr);
	for(int val : arr){
		cout<<val<<" ";
	}
	cout<<endl;
	return 0;
}
