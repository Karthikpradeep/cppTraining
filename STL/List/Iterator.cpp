#include<iostream>
#include<list>

using namespace std;

int main(){

	int size,element;
	list<int> myList;
	cout<<"Enter the number of elements to the list - ";
	cin>>size;

	cout<<"Enter the elements to the list "<<endl;
	for(int i=0;i<size;i++){
		cout<<"Element "<<i+1<<" - ";
		cin>>element;
		myList.push_back(element);
	}

	list<int> :: iterator iter;
	cout<<"Printing elements of the list by traversing list using iterator - ";
	for(iter = myList.begin();iter != myList.end();iter++){
		cout<<*iter<<" ";
	}
	cout<<endl;
	
	 return 0;
}
