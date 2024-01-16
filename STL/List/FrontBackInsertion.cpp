#include<iostream>
#include<list>

using namespace std;

void display(list<int> &myList){
	cout<<"Elements of the list are - ";
	for(int i : myList){
		cout<<i<<" ";
	}
	cout<<endl;
}

int main(){
	int size,element;
	list<int> myList;


	cout<<"Enter the number of elements required - ";
	cin>>size;

	cout<<"Enter the elements of the list "<<endl;
	for(int i=0;i<size;i++){
		cout<<"Element "<<i+1<<" - ";
		cin>>element;
		if(i%2 == 0){
			cout<<"Element "<<element<<" pushed to back"<<endl;
			myList.push_back(element);
		}
		else{
			cout<<"Element "<<element<<" pushed to front"<<endl;
			myList.push_front(element);
		}

	}
	display(myList);


	return 0;
}
