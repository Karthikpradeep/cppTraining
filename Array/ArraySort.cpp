#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int n;
	cout<<"Enter the size of the array - ";
	cin>>n;

	int arr[n];

	cout<<"Enter the elements of the array"<<endl;
	for(int i=0;i<n;i++){
		int elem;
		cin>>elem;
		arr[i] = elem;
	}
	int middle = n/2;
	sort(arr,arr+middle);
	cout<<"First part of the array - ";
	for(int i=0;i<middle;i++){
		cout<<arr[i]<<" ";
	}

	sort(arr+middle,arr+n);
	cout<<"\nSecond part of the array - ";
	for(int i=middle;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}
