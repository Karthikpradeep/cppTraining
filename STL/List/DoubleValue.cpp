#include<iostream>
#include<list>

using namespace std;

void display(list<int> &myList){
        for(int i : myList){
                cout<<i<<" ";
        }
        cout<<endl;
}
void DoublingElement(list<int> &myList){
	list<int> :: iterator iter;
	for(iter = myList.begin();iter != myList.end();++iter){
		*iter = 2*(*iter);
	}
}

	
int main(){
        int size,element,length = 1 ;
        list<int> myList;

        cout<<"Enter the number of elements required - ";
        cin>>size;

        cout<<"Enter the elements of the list "<<endl;
        for(int i=0;i<size;i++){
                cout<<"Element "<<i+1<<" - ";
                cin>>element;
                myList.push_back(element);
        }
	cout<<"Elements of the list are - ";
        display(myList);

	DoublingElement(myList);
	cout<<"Elements after doubling - ";
	display(myList);



	return 0;
}
