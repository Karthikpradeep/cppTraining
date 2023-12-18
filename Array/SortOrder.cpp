#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int n;
	cout<<"Enter the size of the array - ";
	cin>>n;
	int arr[n];
	cout<<"Enter the elements to the array "<<endl;
	for(int i=0;i<n;i++){
		int elem;
		cin>>elem;
		arr[i]=elem;
	}

	cout<<"Enter the order of sorting press A for ascending order and press D for descending order sorting - ";
	char choice;
	cin>>choice;
	if(choice == 'A' || choice == 'a'){
		sort(arr,arr+n);
		for(int i=0;i<n;i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
	else if(choice == 'D' || choice == 'd'){
		sort(arr,arr+n,greater<int>());
		for(int i=0;i<n;i++)
		{
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
	else{
		cout<<"!!! Invalid Input !!!"<<endl;
	}

	return 0;
}


