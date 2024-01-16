#include<iostream>
#include<list>
#include<algorithm>

using namespace std;

int main(){

	list<int> myList1 = {2,10,3,1,7,5};
	list<int> myList2 = {6,5,2,1,0,22};
	myList1.sort();
	myList2.sort();

	myList1.merge(myList2);

	myList1.sort();

	cout<<"Elements after merging - ";
	for(int i : myList1){
		cout<<i<<" ";
	}
	cout<<endl;

	return 0;
}
