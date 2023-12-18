#include <iostream>

using namespace std;

void rotateArray(int arr[], int size, int rotation){

	rotation = rotation % size;
	int temp[size];
	/* store elements to be rotated */
	for(int i=0;i<rotation;i++){
		temp[i]=arr[size-rotation+i];
	}
	/* shift the elements */
	for(int i=0;i<size - rotation;i++){
		temp[rotation+i]=arr[i];
	}
	cout<<"Rotated array - ";
	for(int i=0;i<size;i++){
		cout<<temp[i]<<" ";
	}
	cout<<endl;
}


int main(){
	int size;

	cout<<"Enter the size of the array - ";
	cin>>size;

	int arr[size];

	cout<<"Enter the elements of the array "<<endl;
	for(int i=0;i<size;i++){
		cout<<"Element "<<i+1<<" - ";
		cin>>arr[i];
	}
	int rotation;

	cout<<"Enter the number of rotation - ";
	cin>>rotation;

	rotateArray(arr, size, rotation);

	return 0;
}
