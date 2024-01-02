#include<iostream>

using namespace std;

typedef int(*Funptr)(int);
void applyFunction(int arr[], int size, Funptr ptr){
	 for(int i = 0 ; i < size ; i++){
         cout << ptr(arr[i]) << " ";
	 }
	 cout<<endl;
}
int squaring(int num){
	return num*num;
}

int doubling(int num){
	return 2*num;
}
int main(){
	int size;
        cout<<"Enter the size of the array - ";
        cin>>size;

        int arr[size];
        cout<<"Enter the elements of the array "<<endl;
        for(int i=0;i<size;i++){
                cout<<"Enter the element "<<i+1<<" - ";
                cin>>arr[i];
        }
	cout<<"Elements after squaring - ";
	applyFunction(arr, size, squaring);
	cout<<endl;
	cout<<"Elements after doubling - ";
	applyFunction(arr, size, doubling);
	cout<<endl;
	return 0;
}
