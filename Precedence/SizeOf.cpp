#include <iostream>

using namespace std;

int main(){
	string str="Hello World";
	int arr[] ={1,2,3,4,5};
	cout<<"Size of int - "<<sizeof(int)<<endl;
	cout<<"Length of the array -"<<sizeof(arr)/sizeof(arr[0])<<endl;

	return 0;
}
