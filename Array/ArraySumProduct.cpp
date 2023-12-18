#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n;
	cout<<"Enter the size of the array - ";
	cin>>n;
	int arr[n];

	cout<<"Enter the elements of the array "<<endl;
	for(int i=0;i<n;i++){
		int elem;
		cin>>elem;
		arr[i]=elem;
	}

	int sum=0,product=1,average;
	for(int i=0;i<n;i++){
		sum = sum+arr[i];
		product = product*arr[i];
	}
	average = sum/n;
	sort(arr,arr+n);

	cout<<"Sum - "<<sum<<endl;
	cout<<"Product - "<<product<<endl;
	cout<<"Average - "<<average<<endl;
	cout<<"Smallest element - "<<arr[0]<<endl;
	bool found = false;
	int j=0;
	for( j=0;j<n;j++){
		if(arr[j] != arr[j+1] && j<n-1)
		{
		  found = true;
		  break;
		 }
	}
	if(found == true )
	{
		cout<<"Second smallest element - "<<arr[j+1]<<endl;
	}
	else{
		cout<<"Second smallest element does not exist"<<endl;
	}
	cout<<"Largest element - "<<arr[n-1]<<endl;
	bool check = false;
	int i=0;
	for(i=n-1;i>=0;i--){
		if(arr[i] != arr[i-1] && i>0)
			{
				check = true;
				break;
			}
	}
	if(check == true){
		cout<<"Second largest number - "<<arr[i-1]<<endl;
	}
	else{
		cout<<"Second largest number does not exist"<<endl;
	}

				
	return 0;
}

