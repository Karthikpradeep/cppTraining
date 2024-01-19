// In c++ list DS is a doubly linked list
#include<iostream>
#include<limits>

using namespace std;

struct Node{
	int data;
	Node* prev;
	Node* next;
};

void push_front(Node*& head,int value){
	Node* newNode = new Node;
	newNode->data = value;
	newNode->next = head;
	newNode->prev = nullptr;
	head = newNode;
	cout<<"New node inserted at the beginning"<<endl;
}

void push_back(Node*& head, int value){
	Node* newNode = new Node;
	newNode->data = value;
	newNode->next = nullptr;
	if(head == nullptr){
		newNode->prev=nullptr;
		head = newNode;
		return;
	}
	Node* temp = head;
	while(temp->next != nullptr){
		temp=temp->next;
	}
	temp->next = newNode;
	newNode->prev = temp;
	cout<<"New node created at the end"<<endl;
	
}

void pop_front(Node*& head){
	if(head == nullptr){
		cout<<"List is empty so deletion not possible"<<endl;
		return;
	}
	else if(head->next == nullptr){
		head=nullptr;
		delete head;
		return;
	}
	Node* newNode;
	newNode=head;
	head=head->next;
	head->prev = nullptr;

	delete newNode;
}

void pop_back(Node*& head){
	if(head == nullptr){
		cout<<"List is empty so deletion not possible"<<endl;
	}
	else if(head->next == nullptr){
		head=nullptr;
		delete head;
		return;
	}
	Node* current = head;
	while(current->next != nullptr){
		current=current->next;
	}
	Node* prev = current->prev;
	prev->next = nullptr;
	delete current;
}

void display(Node*& head){
	if(head == nullptr){
		cout<<"List is empty "<<endl;
	}
	Node* current = head;
	while(current != nullptr){
		cout<<current->data<<" ";
		current = current->next;
	}
	cout<<endl;
}

void size(Node* head){
	int count = 0;
	if(head == nullptr){
		cout<<"Empty List"<<endl;
		return;
	}
	Node* current = head;
	while(current != nullptr){
		current=current->next;
		count++;
	}

	cout<<"Size of the lis is - "<<count<<endl;
}

int main(){
	Node* head = nullptr;
	int choice,value;
	while(true){
		cout<<"\n---- MENU ----"<<endl;
		cout<<"1. push_front "<<endl;
		cout<<"2. push_back "<<endl;
		cout<<"3. pop_front "<<endl;
		cout<<"4. pop_back "<<endl;
		cout<<"5. Display the list " <<endl;
		cout<<"6. Size of the list "<<endl;
		cout<<"7. Exit from the program"<<endl;

		cout<<"\nEnter your choice - ";
		if(cin>>choice){
			switch(choice){
				case 1:
					cout<<"Enter the value to be inserted start - ";
					cin>>value;
					push_front(head,value);
					break;
				case 2: 
					cout<<"Enter the value to be inserted at end - ";
					cin>>value;
					push_back(head, value);
					break;
				case 3:
					pop_front(head);
					break;
				case 4: 
					pop_back(head);
					break;
				case 5:
					cout<<"List - ";
					display(head);
					break;
				case 6:
					size(head);
					break;
				case 7:
					cout<<"Exiting the program"<<endl;
					return 0;
				default:
					cerr<<"!!!! Invalid Input !!!!"<<endl;
					break;

				}
		}
		else{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			cerr<<"Please enter the numbers provided in the menu"<<endl;
		}
	}
	return 0;
}
