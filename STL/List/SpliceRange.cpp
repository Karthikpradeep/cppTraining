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
        int size,element,start,last,pos;
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

        cout<<"Enter the starting position in list1 - ";
        cin>>start;
	cout<<"Enter the ending position in list1 - ";
	cin>>last;
	cout<<"Enter the position in list 2 - ";
	cin>>pos;

        list<int> :: iterator iter1;
	list<int> :: iterator iter2;
	iter1 = myList1.begin();
	advance(iter1, start);
	iter2 = myList1.begin();
	advance(iter2, last);
	list<int> :: iterator iter3;
	iter3 = myList2.begin();
	advance(iter3, pos);

	myList2.splice(iter3,myList1,iter1,iter2);

	cout<<"List2 after splicing "<<endl;
	displayList(myList2);

	return 0;
}

	
