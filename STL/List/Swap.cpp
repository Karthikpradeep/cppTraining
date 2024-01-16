#include<iostream>
#include<list>
#include<algorithm>

using namespace std;

void display(list<int> myList){
        cout<<"Elements of the list are - ";
        for(int i : myList){
                cout<<i<<" ";
        }
        cout<<endl;
}
int main(){
        int size,element;
        list<int> myList1;

        cout<<"Enter the number of elements required for list 1 - ";
        cin>>size;

        cout<<"Enter the elements of the list "<<endl;
        for(int i=0;i<size;i++){
                cout<<"Element "<<i+1<<" - ";
                cin>>element;
                myList1.push_back(element);
        }
	list<int> myList2;

        cout<<"Enter the number of elements required for list 2 - ";
        cin>>size;

        cout<<"Enter the elements of the list "<<endl;
        for(int i=0;i<size;i++){
                cout<<"Element "<<i+1<<" - ";
                cin>>element;
                myList2.push_back(element);
        }
	cout<<"Element of list 1 before swapping "<<endl;
	display(myList1);
	cout<<"Element of list 2 before swapping "<<endl;
        display(myList2);
	swap(myList1,myList2);
        cout<<"Element of list 1 after swapping "<<endl;
        display(myList1);
        cout<<"Element of list 2 after swapping "<<endl;
        display(myList2);
	return 0;
}



