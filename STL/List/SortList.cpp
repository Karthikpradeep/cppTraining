#include<iostream>
#include<list>
#include<algorithm>

using namespace std;

int main(){
	int size,element;
	list<int> myList;
	cout<<"Enter the number of element in the list - ";
	cin>>size;

	cout<<"Enter elements in the list"<<endl;
	for(int i=0;i<size;i++){
		cout<<"Enter element "<<i+1<<" - ";
		cin>>element;
		myList.push_back(element);
	}
	myList.sort();
	cout<<"Elements of the list are - ";
	for(int i : myList){
		cout<<i<<" ";
	}
	cout<<endl;

	return 0;
}
