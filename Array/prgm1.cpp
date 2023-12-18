#include <iostream>

using namespace std;

int main(){
	int n;
	cout<<"Enter the size of array - ";
	cin>>n;
	int arr[n];
	cout<<"\nEnter the elements of array - "<<endl;
	for(int i=0;i<n;i++){
		int elem;
		cin>>elem;
		arr[i] = elem;
	}
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}
