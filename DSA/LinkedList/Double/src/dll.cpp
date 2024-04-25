#include <DLLHeader.h>

DLL::DLL(){
}

DLL::~DLL(){
}

void DLL::insertAtBeginning(Node*& head, int value){
	Node* newNode = new Node;
	newNode->data = value;
	newNode->next = head;
	newNode->prev = nullptr;

	head = newNode;
	cout<<"\n New node with value "<<value<<" Created "<<endl;
}

void DLL::push_front(Node*& head, int value){
	insertAtBeginning(head, value);
}
void DLL::insertAtEnd(Node*& head, int value){
	Node* newNode = new Node;
	newNode->data = value;
	newNode->next = nullptr;

	if(head == nullptr){
		newNode->prev = nullptr;
		head = newNode;
		return;
	}
	Node* temp = head;
	while(temp->next != nullptr){
		temp = temp->next;
	}
	temp->next = newNode;
	newNode->prev = temp;
	cout<<"New node with value "<<value<<" added at the end of the list"<<endl;
}

void DLL::push_back(Node*& head, int value){
	insertAtEnd(head,value);
}

void DLL::deleteNode(Node*& head, int value){
	if(head == nullptr){
		cout<<"The list is empty"<<endl;
		return;
	}
	Node* current = head;
	Node* temp = nullptr;
	while(current != nullptr && current->data != value){
		temp = current;
		current = current->next;
	}
	if(current == nullptr){
		cout<<"The value "<<value<<" is not present in the list"<<endl;
		return;
	}
	if(current->prev == nullptr){
		head = current->next;
		if(head != nullptr){
			head->prev = nullptr;
		}
	}
	else if(current->next == nullptr){
		temp->next = nullptr;
	}
	else {
		temp->next = current->next;
		current->next->prev = temp;
	}
	delete current;
	cout<<"Element "<<value<<" deleted from the list"<<endl;
}	

void DLL ::removeNode(Node*& head, int value){
	deleteNode(head, value);
}

void DLL::display(Node* head){
	if(head == nullptr){
		cout<<"Empty List"<<endl;
		return;
	}
	else{
		cout<<"Elements of the list are - ";
		Node* temp = head;
		while(temp != nullptr){
			cout<<temp->data<<" ";
			temp = temp->next;
		}
	}
	cout<<endl;
}

