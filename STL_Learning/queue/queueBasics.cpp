#include<iostream>
#include<queue>
using namespace std;

int main(){
	queue<int> nums;
	int entries,elements;

	cout<<"Enter the number of entries - ";
	cin>>entries;
	//entring elements to the queue
	cout<<"Enter the numbers - ";
	for(int i=0;i<entries;i++){
		cin>>elements;
		nums.push(elements);
	}

        cout<<endl;

	// creating a copy of queue num
	queue<int> copy_nums = nums;
	
	//printing all elements of the queue
	while(! copy_nums.empty()){
		cout<<copy_nums.front()<<" ";
		copy_nums.pop();

	}

	//printing elements in the front and back
	cout<<"\nElement in the front - "<<nums.front()<<endl;
	cout<<"Element in the back - "<<nums.back()<<endl;
	cout<<endl;
	return 0;
}


