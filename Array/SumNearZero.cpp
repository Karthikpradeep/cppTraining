#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

void nearZero(int arr[],int size){
	sort(arr, arr+size);

	int left=0,right = size-1;
	int nearestSum =INT_MAX;
	int number1, number2;

	while(left<right){
		int currentSum = arr[left]+arr[right];

		if(abs(currentSum)<abs(nearestSum)){
			nearestSum=currentSum;
			number1 = arr[left];
			number2 = arr[right];
		}

		if(currentSum<0){
			left++;
		}
		else{
			right--;
		}
	}
	cout<<"Two elements with sum near to zero are "<<number1<<" and "<<number2<<endl;

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

	nearZero(arr, size);

	return 0;
}


