#include <iostream>

using namespace std;

int main(){
	int arr[] = { 2,3,5,7,11 };
	int arrLength = sizeof(arr)/sizeof(arr[0]);
	cout<<"Reverse of the array is - ";
	for(int i=arrLength-1;i>=0;i--){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}
