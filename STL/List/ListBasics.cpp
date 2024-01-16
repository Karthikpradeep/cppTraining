#include<iostream>
#include<list>
#include<algorithm>
using namespace std;

void display(list<int> &myList){
	cout<<"Elements of the list are - ";
	for(int i : myList){
		cout<<i<<" ";
	}
	cout<<endl;
}

int main(){
	int size,element,length = 1 ;
	list<int> myList;

	//insertion
	cout<<"Enter the number of elements required - ";
	cin>>size;

	cout<<"Enter the elements of the list "<<endl;
	for(int i=0;i<size;i++){
		cout<<"Element "<<i+1<<" - ";
		cin>>element;
		myList.push_back(element);
	}
	
	display(myList);
	//deletion
	//Deleting the first and last element
	cout<<"Deleting the last element"<<endl;
	myList.pop_back();//delete last element
	display(myList);
	cout<<"Deleting the first element"<<endl;
	myList.pop_front();//delete first element
	display(myList);
	
	//deleting the custom element
	cout<<"\nEnter the element to be deleted - ";
	cin>>element;
	
	list<int> :: iterator iter;
	 iter = find(myList.begin(),myList.end(),element);  //traversing

	if(iter != myList.end()){
		myList.erase(iter);
		cout<<"Element "<<element<<" deleted from the list"<<endl;
		display(myList);
	}
	else{
		cout<<"Element "<<element<<" is not present in the list"<<endl;
	}




	return 0;

}


