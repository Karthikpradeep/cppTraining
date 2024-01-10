#include<iostream>
#include<cstdlib>

using namespace std;

int main(){

	int size;
	cout<<"Enter the size of the array - ";
	cin>>size;

	int* array;

	array = (int*)calloc(size,sizeof(int));

	if(array == nullptr){
		cerr<<"!!! Memory allocation failed !!!"<<endl;
		return 1;
	}
	else{
		cout<<"Allocated memory spaces "<<endl;
		for(int i=0;i<size;i++){
		cout<<array[i]<<" ";
		}
		cout<<endl;
		cout<<"Enter the data to the array "<<endl;
		for(int i=0;i<size;i++){
			cout<<"Array ["<<i<<"] - ";
			cin>>array[i];
		}

		cout<<endl;
		cout<<"The values of the array are - ";
	        for(int i=0;i<size;i++){
			cout<<array[i]<<" ";
		}
		cout<<endl;
		free(array);
		return 0;
	}
}	
			
