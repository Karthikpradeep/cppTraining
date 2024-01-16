#include<iostream>
#include<list>

using namespace std;

void displayList(list<int> &myList){
	for(int i : myList){
		cout<<i<<" ";
	}
	cout<<endl;
}
void ReverseList(list<int> &myList){
	list<int> :: iterator start;
	list<int> :: iterator end;
	start = myList.begin();
	end = myList.end();//iterator pointing to element after the last element
	--end;


	while(start != end && distance(start,end)>0){
		swap(*start,*end);
		++start;
		--end;
	}
}

int main(){
	int size,element;
	cout<<"Enter the number of element to be inserted in list - ";
	cin>>size;
	
	list<int> myList;
	cout<<"Enter elements to the list"<<endl;
	for(int i=0;i<size;i++){
		cout<<"Element "<<i+1<<" - ";
		cin>>element;
		myList.push_back(element);
	}
	cout<<"The elements of the list are - ";
	displayList(myList);
	cout<<"Reversing the list elements"<<endl;
	ReverseList(myList);
	cout<<"Elements after reversing - ";
	displayList(myList);

	return 0;
}

