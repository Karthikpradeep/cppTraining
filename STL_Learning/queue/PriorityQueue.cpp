#include<iostream>
#include<queue>

using namespace std;

int main(){
	//creating a max heap priority queue
	priority_queue<int> nums;  // max heap
	//priority_queue<int, vector<int>, greater<int>> nums; min heap 
	int entries,element;
	string name;
	cout<<"Enter the number of entries needed - ";
	cin>>entries;

	cout<<"Enter the values to the queue "<<endl;
	for(int i=0;i<entries;i++){
		cin>>element;
		nums.push(element);
	}
	priority_queue<int> copyNums = nums;
	//printing the elements of the queue
	for(int i=0;i<nums.size();i++){
		cout<<copyNums.top()<<" ";
		copyNums.pop();
	}
	cout<<endl;

	priority_queue<string, vector<string>, greater<string>> names;//min heap
	cout<<"Enter the number of entries - ";
	cin>>entries;
	cin.ignore();
	cout<<"Enter the values to the queue "<<endl;
	for(int i=0;i<entries;i++){
		getline(cin,name);
		names.push(name);
	}
	cout<<endl;
	for(int i=0;i<entries;i++){
		cout<<names.top()<<" ";
		names.pop();
	}
	cout<<endl;

	return 0;
}
