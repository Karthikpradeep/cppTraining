#include<iostream>
#include<list>

using namespace std;

void display(list<int> myList){
	cout<<"Elements of the list are - ";
	for(int i : myList){
		cout<<i<<" ";
	}
	cout<<endl;
}

int Search(list<int> &myList,int searchElement){
	int count = 0;
	list<int> :: iterator iter;
	list<int> :: iterator last;
	last = myList.end();
	--last;
	for(iter = myList.begin(); iter != myList.end(); ++iter){
		if(*iter == searchElement){
			return count;
		}
		if(*iter == *last){
		       return -1;
		}
		count++;
	}		

}
int main(){
	int size,element,searchElement,isPresent;
	list<int> myList;

	cout<<"Enter the number of elements required - ";
	cin>>size;

	cout<<"Enter the elements of the list "<<endl;
	for(int i=0;i<size;i++){
		cout<<"Element "<<i+1<<" - ";
		cin>>element;
		myList.push_back(element);
	}
	display(myList);

	cout<<"Enter the element to be searched in the list - ";
	cin>>searchElement;
	
	isPresent = Search(myList, searchElement);
	if(isPresent == -1){
		cout<<"The element "<<searchElement<<" not found in the list"<<endl;
	}
	else{
		cout<<"The element "<<searchElement<<" is present in the list at index - "<<isPresent<<endl;
	}
	
	return 0;
}
