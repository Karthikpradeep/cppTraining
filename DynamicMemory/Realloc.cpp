#include<iostream>
#include<cstdlib>

using namespace std;

int main(){
	int size;
	
	cout<<"Enter the size of the array - ";
	cin>>size;

	int* arr = (int*)malloc(size*sizeof(int));

	if(arr == nullptr){
		cout<<"!!! Memory allocation failed !!!"<<endl;
		return 1;
	}
	cout<<"Memory allocated successfully"<<endl;
	cout<<"Enter the elements in the array"<<endl;
	for(int i=0;i<size;i++){
		cout<<"Array ["<<i<<"] - ";
		cin>>arr[i];
	}
	cout<<"Elements in the array are"<<endl;
	for(int i=0;i<size;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	
	int newSize;
	cout<<"Enter new size for resizing the array - ";
	cin>>newSize;

	int* newArr = (int*)realloc(arr,newSize*sizeof(int));
	
	if(newArr == nullptr){
		cout<<"!!! Memory allocation failed !!!"<<endl;
		return 1;
	}
	
	arr = newArr;
	cout<<"Enter additional elements to array"<<endl;
	if(newSize>size){
	for(int i=size;i<newSize;i++){
		cin>>arr[i];
	}
	}
	
	
	cout<<"Updated array is - ";
	for(int i=0;i<newSize;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	free(arr);
	return 0;

			

}
