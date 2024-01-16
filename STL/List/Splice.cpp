#include<iostream>
#include<list>

using namespace std;
void displayList(list<int> &myList){
        for(int i : myList){
                cout<<i<<" ";
        }
        cout<<endl;
}

int main(){
	int size,element,pos;
	cout<<"Enter the number of element to be inserted in list1 - ";
	cin>>size;

	list<int> myList1;
	cout<<"Enter elements to the list"<<endl;
	for(int i=0;i<size;i++){
		cout<<"Element "<<i+1<<" - ";
		cin>>element;
		myList1.push_back(element);
	}
	cout<<"The elements of the list are - ";
	displayList(myList1);
	
	cout<<"Enter the number of element to be inserted in list2 - ";
        cin>>size;

        list<int> myList2;
        cout<<"Enter elements to the list"<<endl;
        for(int i=0;i<size;i++){
                cout<<"Element "<<i+1<<" - ";
                cin>>element;
                myList2.push_back(element);
        }
        cout<<"The elements of the list are - ";
        displayList(myList2);

	cout<<"Enter the poisition in list1 where list2 should be inserted - ";
	cin>>pos;

	list<int> :: iterator iter;

	iter = myList1.begin();
	advance(iter, pos);
	myList1.splice(iter,myList2);

	cout<<"List1 after splicing - ";
	displayList(myList1);

	return 0;
}



