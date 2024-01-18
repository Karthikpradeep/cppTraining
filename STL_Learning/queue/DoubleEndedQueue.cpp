#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;

int main(){
	deque<int> nums;
	int entries,element;
	cout<<"Enter the number of entries needed - ";
	cin>>entries;
	//pushing element to the queue
	cout<<"Enter the elements to the queue - ";
	for(int i=0 ; i<entries; i++){
		cin>>element;
		nums.push_back(element);
	}
	//printing elements in forward direction
	cout<<"Elements of the queue are - ";
	for(auto it = nums.cbegin(); it != nums.cend(); ++it){
		cout<<*it<<" ";
	}
	cout<<endl;
	//Printing elements in reverse direction
	cout<<"Elements of the queue are - "; 
	for(auto it = nums.crbegin(); it != nums.crend(); ++it){
		cout<<*it<<" ";
	}

	cout<<endl;
	return 0;
}
