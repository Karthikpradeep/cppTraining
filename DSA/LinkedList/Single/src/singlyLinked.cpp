#include <singleLLHeader.h>

SinglyLinked::SinglyLinked(){
}

SinglyLinked::~SinglyLinked(){
}

void SinglyLinked::insertAtBeginning(Node*& head, int value){
	Node* newNode = new Node;
	newNode->data = value;
	newNode->next = head;
	head = newNode;
	cout<<"Node inserted at the beginning"<<endl;
}

void SinglyLinked::insertAtFront(Node*& head, int value){
	insertAtBeginning(head,value);
}

void SinglyLinked::insertAtEnd(Node*& head, int value){
	
	Node* newNode = new Node;
	newNode->data = value;
	newNode->next = nullptr;

	if( head == nullptr){
		head = newNode;
	}
	else{
		Node* temp = head;
		while(temp->next != nullptr){
			temp = temp->next;
		}
		temp->next = newNode;
	}
	cout<<"New node created at the end "<<endl;
}

void SinglyLinked::insertAtRear(Node*& head, int value){
	insertAtEnd(head,value);
}

void SinglyLinked::deleteNode(Node*& head, int value){
	if(head == nullptr){
		cout<<"Empty List"<<endl;
		return;
	}
	Node* temp = head;
	Node* prev = nullptr;

	while(temp != nullptr && temp->data != value){
		prev = temp;
		temp = temp->next;
	}

	if( temp == nullptr){
		cout<<"The value "<<value<<" is not present in the list"<<endl;
		return;
	}
	if(prev == nullptr){
		head = temp->next;
		
	}
	else{
		prev->next = temp->next;
		
	}
	delete temp;
	cout<<"Node with value "<<value<<" deleted from the list"<<endl;
}

void SinglyLinked::removeNode(Node*& head, int value){
	deleteNode(head,value);
}

void SinglyLinked::display(Node* head){
	if(head == nullptr){
		cout<<"Empty list"<<endl;
	}
	else{
		cout<<"The elements of the list are - ";
		Node* temp = head;
		while(temp != nullptr){
			cout<<temp->data<<" ";
			temp = temp->next;
		}
		cout<<endl;
	}
}
