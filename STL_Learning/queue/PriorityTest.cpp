#include<iostream>
#include<queue>

using namespace std;

void display(priority_queue<int> displayQueue){
	int length = displayQueue.size();
	cout<<"\nElements of the queue are - ";
	for(int i=0;i<length;i++){
		cout<<displayQueue.top()<<" ";
		displayQueue.pop();
	}
	cout<<endl;
}
int main(){
	int entries1,entries2,element;

	priority_queue<int> salary; //max heap ie -> highest value will be in the front of the queue
	priority_queue<int, vector<int>, greater<int>> empId;// min heap ie -> least value will be in the front of the queue

	cout<<"Enter the number of entries needed for salary - ";
	cin>>entries1;

	cout<<"Enter the number of entries needed for employee id - ";
	cin>>entries2;

	cout<<"Enter the salaries - ";
	for(int i=0;i<entries1;i++){
		cin>>element;
		salary.push(element);
	}
	display(salary);
	cout<<"\nEnter teh empId - ";
	for(int i=0;i<entries2;i++){
		cin>>element;
		empId.push(element);
	}
	cout<<"\nElements of the queue are - ";
	for(int i=0;i<empId.size();i++){
		cout<<empId.top()<<" ";
		empId.pop();
	}
	cout<<endl;

	return 0;
}

