#include<iostream>

using namespace std;
void evencheck(int arr[],int size, bool (*evenLambda)(int)){
	for(int i=0;i<size;i++){
		if(evenLambda(arr[i])){
			cout<<arr[i]<<" ";
		}
		}
	cout<<endl;

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
	auto evenLambda = [](int x){
		return x%2 == 0;
	};
	evencheck(arr,size,evenLambda);
	return 0;
}
