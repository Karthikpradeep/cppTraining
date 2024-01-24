#include<iostream>
#include<unordered_set>

using namespace std;

int main(){

	unordered_multiset<int> mySet;

	mySet={10,2,1,2,4,1,3,5,1,6,7};

	cout<<"Elements of the unordered multiset are - ";
	for(int i :mySet){
		cout<<i<<" ";
	}
	cout<<endl;
	cout<<"Erasing all instances of 1"<<endl;
	mySet.erase(1);
	cout<<"Set after erasing all instance of element 1 : ";
	for(int i :mySet){
                cout<<i<<" ";
        }
	cout<<endl;
	//empty() to check whether the set is empty or not
	//size() to check the size
	cout<<"Count of 2 in the set - "<<mySet.count(2)<<endl;
	// find() to check whether a element is present in the set or not
	

	return 0;
}
