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
void uniqueElement(list<int> &myList){
	myList.unique();
}	
int main(){
        int size,element;
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
	cout<<"List after removing repeating elements - ";
	uniqueElement(myList);
	display(myList);
	cout<<endl;
	
	return 0;
}
