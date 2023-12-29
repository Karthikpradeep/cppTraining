#include <iostream>

using namespace std;

void display(int* aptr,int size){
	cout<<"Array elements are - ";
	for(int i=0;i<size;i++){
		cout<<aptr[i]<<" ";
	}
	cout<<endl;
}

void SumAndAverage(int* ptr, int size){
	int sum = 0;
	for(int i=0;i<size;i++){
		sum+=ptr[i];
	}
	cout<<"Sum of the elements are - "<<sum<<endl;
	float average;
	average=sum/size;
	cout<<"Average of the elements is - "<<average<<endl;
}

int main(){
	int size,i=0; 
	int* ptr; 

	cout<<"Enter the size of the array - ";
	cin>>size;
	//dynamic allocation of integer array based on user input
	ptr = new int[size];

	//looping to take value for each element from user
	
	for(i=0;i<size;i++){
		cout<<"Enter the element "<<i+1<<" - ";
		cin>>ptr[i];
	}
	display(ptr,size); // display elements of the array
	SumAndAverage(ptr,size); // calculate sum and average of the array
	delete[] ptr;
	return 0;
}

