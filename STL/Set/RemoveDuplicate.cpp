#include<iostream>
#include<set>
#include<vector>

using namespace std;

int main(){
	vector<int> myVect;
	int size,element;
	cout<<"Enter the number of elements to be inserted to the set - ";
	cin>>size;

	cout<<"Enter the elements to the sets "<<endl;
	for(int i =0;i<size;i++){
		cout<<"Element "<<i+1<<" - ";
		cin>>element;
		myVect.push_back(element);
	}
	cout<<"Elements of the list are - ";
	for(int i : myVect){
		cout<<i<<" ";
	}
	set<int> mySet(myVect.begin(),myVect.end());
	vector<int> ResultVect(mySet.begin(),mySet.end());

	cout<<"\nVector after removing duplicates - ";
	for(int i : ResultVect){
		cout<<i<<" ";
	}
	cout<<endl;


	return 0;
}
