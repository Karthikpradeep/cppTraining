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
        int size,element,searchElement,occurences;
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
        cout<<"Enter the element to count the occurence - ";
        cin>>searchElement;
	occurences = count(myList.begin(),myList.end(),searchElement);

	cout<<"Occurence of element of the list is - "<<occurences<<endl;

	return 0;
}
