#include <stackHeader.h>

Stack::Stack(){
}

Stack::~Stack(){
}

void Stack::insertNode(Node*& top,int value){
	Node* newNode = new Node;
	newNode->data = value;
	if(top == nullptr){
		newNode->next = nullptr;
		top = newNode;
	}
	else{
		newNode->next = top;
		top = newNode;
	}
}

void Stack::push(Node*& top,int value){
	insertNode(top, value);
}

void Stack::removeNode(Node*& top){
	if(top == nullptr){
		cout<<"The stack is empty"<<endl;
		return;
	}
	cout<<"Poping the top element"<<endl;
	Node* temp;
	temp = top;
	top = top->next;
	temp->next = nullptr;
	delete temp;
}

void Stack::pop(Node*& top){
	removeNode(top);
}

void Stack::firstNode(Node*& top){
	if(top==nullptr){
		cout<<"The stack is empty"<<endl;
		return;
	}
	cout<<"Top element is - "<<top->data<<endl;
}

void Stack::topNode(Node*& top){
	firstNode(top);
}

