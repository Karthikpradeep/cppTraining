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
		return 0;
	}
	else{
		cout<<"Memory allocated to the array"<<endl;
		for(int i=0;i<size;i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
		cout<<"Enter the value of the array "<<endl;
		for(int i=0;i<size;i++){
			cout<<"array ["<<i<<"] - ";
			cin>>arr[i];
		}

		cout<<"Populated array "<<endl;
		for(int i=0;i<size;i++){
			cout<<arr[i]<<" ";
		}
		free(arr);
		cout<<endl;
		cout<<"When memory is deallocated it will show garbage value"<<endl;
		for(int i=0;i<size;i++){
                        cout<<arr[i]<<" ";
                }

		cout<<endl;
		return 0;
	}
}

