#include <queueHeader.h>

Queue::Queue(){
}

Queue::~Queue(){
}

void Queue::push(Node*& front,Node*& rear,int value){
	Node* newNode = new Node();
	newNode->data = value; 
	if(front == nullptr && rear == nullptr){
		newNode->next = nullptr;
		front = newNode;
		rear = newNode;
		return;
	}
	rear->next = newNode;
	rear = newNode;
	rear->next = nullptr;
}

void Queue::enqueue(Node*& front,Node*& rear,int value){
	push(front,rear,value);
}

void Queue::pop(Node*& front,Node*& rear){
	if(front == nullptr){
		cout<<"The queue is empty"<<endl;
		return;
	}
	Node* temp;
	temp = front;
	front = front->next;
	if(front == nullptr){
		rear = nullptr;
	}
	temp->next = nullptr;
	delete temp;
}

void Queue::dequeue(Node*& front,Node*& rear){
	pop(front,rear);
}

void Queue::first(Node* front){
	if(front == nullptr){
		cout<<"Queue is empty"<<endl;
		return;
	}
	cout<<"Element at front the queue is - "<<front->data<<endl;
}	

void Queue::last(Node* rear){
	if(rear == nullptr){
		cout<<"Queue is empty"<<endl;
		return;
	}
	cout<<"Element at the rear of the queue is - "<<rear->data<<endl;
}

void Queue::display(Node* front){
	if(front == nullptr){
		cout<<"The queue is empty"<<endl;
		return;
	}
	Node* current;
	 current = front;
	 while(current != nullptr){
		 cout<<current->data<<" ";
		 current = current->next;
	 }
	 cout<<endl;
}
