#include<iostream>

using namespace std;

class DynamicArray{
	private:
		int* arr;
		int size;
	public:
		DynamicArray(int s){
			size = s;
			arr = new int[size];
			cout<<"Dynamic array object created of size - "<<size<<endl;
		}
		~DynamicArray(){
			delete[] arr;
			cout<<"Dynamic array object deleted"<<endl;
		}

		void setData(){
			for(int i=0;i<size;i++){
				cout<<"Enter the element "<<i+1<<" - ";
				cin>>arr[i];
			}
		}

		void getData(){
			cout<<"values of the array are - ";
			for(int i=0;i<size;i++){
				cout<<arr[i]<<" ";
			}
			cout<<endl;
		}

};

int main(){
	int num;
	cout<<"Enter the size of the array - ";
	cin>>num;
	DynamicArray array(num);
	array.setData();
	array.getData();
	
}
