#include<iostream>
#include<queue>

using namespace std;

void display(queue<int> displayQueue){
	cout<<"Elements of the queue - ";
	int length = displayQueue.size();
	for(int i=0;i<length;++i){
		cout<<displayQueue.front()<<" ";
		displayQueue.pop();
	}
	cout<<endl;
}

int main(){
	int entries,element;
	queue<int> myQueue;

	cout<<"Enter the number of entries needed to queue - ";
	cin>>entries;

	cout<<"Enter the values to the queue - ";
	for(int i=0;i<entries;i++){
		cin>>element;
		myQueue.push(element);
	}
	display(myQueue);
	cout<<"\nSize of the queue - "<<myQueue.size()<<endl; 
	

	return 0;
}


