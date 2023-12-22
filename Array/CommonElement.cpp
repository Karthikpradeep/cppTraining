#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int num;

	cout<<"Enter the number of arrays - ";
	cin>>num;

	int arr[num][20];

	for(int i=0;i<num;i++){
		int size;

		cout<<"Enter the size of Array "<<i+1<<" - ";
		cin>>size;

		for(int j=0;j<size;j++){
			cout<<"Element "<<j+1<<" - ";
			cin>>arr[i][j];
		}
	}
	cout<<"Entered arrays are "<<endl;
	for(int i=0;i<num;i++){
		

	return 0;
}



