//associative containers have sorted values which can be quickly searched
//Same as set with multiple values
//	clear() -> remove all elements
//	erase() -> remove all ocuurence of a single element
//	erase(mySet.find()) -> remove a single occurence
#include<iostream>
#include<set>

using namespace std;

int main(){
	multiset<int,greater<int>> mySet; //descenting order set;
	int entries,element;
	cout<<"Enter the number of entries needed - ";
	cin>>entries;
	cout<<"Enter the elements to the multiset "<<endl;
	for(int i=0;i<entries;i++){
		cout<<"Element "<<i+1<<" - ";
		cin>>element;
		mySet.insert(element);
	}
	cout<<"Elements of the list are - ";
	for(int i : mySet){
		cout<<i<<" ";
	}
	cout<<endl;

	return 0;
}
