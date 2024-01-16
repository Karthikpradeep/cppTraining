#include<iostream>
#include<list>
#include<algorithm>

using namespace std;

void displayList(list<int> &myList){
	for(int i : myList){
		cout<<i<<" ";
	}
	cout<<endl;
}
void EraseElement(list<int> &myList,int element){
	myList.remove(element);
}
int main(){
	int size,element;

	cout<<"Enter the number of elements to the list - ";
	cin>>size;
	list<int> myList;
	cout<<"Enter the elements to the list"<<endl;
	for(int i=0;i<size;i++){
		cout<<"Element "<<i+1<<" - ";
		cin>>element;
		myList.push_back(element);
	}
	cout<<"Elements of the list are - ";
	displayList(myList);
	cout<<"\n Enter element to be removed - ";
	cin>>element;

	cout<<"Deleting element "<<element<<" from the list"<<endl;
	EraseElement(myList, element);
	cout<<"List after removing element - ";
	displayList(myList);
	return 0;
}

	
