#include <iostream>

using namespace std;

void display(int* aptr,int size){
	cout<<"Array elements are - ";
	for(int i=0;i<size;i++){
		cout<<*(aptr+i)<<" ";
	}
	cout<<endl;
}

void SumAndAverage(int* ptr, int size){
	int sum = 0;
	for(int i=0;i<size;i++){
		sum+=*(ptr+i);
	}
	cout<<"Sum of the elements are - "<<sum<<endl;
	float average;
	average=sum/size;
	cout<<"Average of the elements is - "<<average<<endl;
}

void MinMax(int* ptr, int size){
	int max = ptr[0];
	int min = ptr[0];

	for(int i=0;i<size-1;i++){
		if(max<ptr[i+1]){
			max = ptr[i+1];
		}
		if(min>ptr[i+1]){
			min = ptr[i+1];
		}
	}
	cout<<"Min element in the array is - "<<min<<endl;
	cout<<"Max element in the array is - "<<max<<endl;
}

void SearchElement(int* ptr, int size, int key){
	int index;
	bool isPresent= false;
	for(int i=0;i<size;i++){
		if(ptr[i] == key){
			isPresent = true;
			index = i;
		}
	}
	if(isPresent == true){
		cout<<"The element "<<key<<" is present in the array at index "<<index<<endl;
	}
	else{
		cout<<"The element "<<key<<" is not present in the array"<<endl;
	}
}
int main(){
	int size,i=0,key; 
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
	MinMax(ptr,size); //min and max element in the array
	cout<<"Enter the element to be searched in the array - ";
	cin>>key;
	SearchElement(ptr, size, key);
	delete[] ptr;
	return 0;
}

