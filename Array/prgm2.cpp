#include <iostream>
#include <iterator>

using namespace std;

int main(){
	
	int arr[] = {10,2,30,16,100,0};
	cout<<"Enter the element to be checked in the array - ";
	int check;
	cin>>check;
	int i=0;
	bool found = false;
	int length = sizeof(arr)/sizeof(arr[0]);
	for( i=0;i<length;i++){
		if(arr[i] == check)
		{
			found = true;
			break;
		}
	}
	if(found == true)
	{
		cout<<"Element "<<check<<" found at index - "<<i<<endl;
	}
	else{
		cout<<"Element not found in the array"<<endl;
	}
	return 0;
}

