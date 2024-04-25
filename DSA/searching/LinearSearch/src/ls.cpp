#include <lsHeader.h>

LinearSearch::LinearSearch(){
	element = 0;
	flag = 0;

}

LinearSearch::~LinearSearch(){
	delete[] arr;
}

void LinearSearch::addElement(int size){
	arr = new int[size];
	cout<<"Enter the elements - ";
	for(int i=0;i<size;i++){
		cin>>arr[i];
	}
}

void LinearSearch::search(int size,int element){
	for(int i=0;i<size;i++){
		if(arr[i] == element){
			flag = 1;
		}
	}
		if(flag == 1){
			cout<<"Element "<<element<<" found "<<endl;

		}
		else{
			cout<<"Element not present"<<endl;
		}
}
		


