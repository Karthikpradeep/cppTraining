#include<iostream>
#include<array> // to use .at() method

using namespace std;

void display(int arr[],int size){
	cout<<"Elements of the array are - ";
	for(int i=0;i<size;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
int main(){
	int arr[] = {1,2,3,4,5};// traditionl c style array declaration
	int length = sizeof(arr)/sizeof(arr[0]);
	display(arr,length);

	array<int,4> arr1 = {1,2,3,4};//c++ STL style fixed array
	cout<<"Size of the array arr1 is - "<<arr1.size()<<endl;
	
	array<int,6> arr2;
	cout<<"Enter 6 elements of the array  "<<endl;
	for(int i =0;i<arr2.size();i++){
		cout<<"Element "<<i+1<<" - ";
		cin>>arr2[i];
	}
	for(int i : arr2){
		cout<<i<<" ";
	}
	cout<<endl;
	return 0;
}


