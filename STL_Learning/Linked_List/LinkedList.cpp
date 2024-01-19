// In c++ forward_list is a singly linked list DS.

#include<iostream>
#include<limits>

using namespace std;

struct Node{
	int data;
	Node* next;
};

void insertAtBeginning(Node*& head, int value){
	Node* newNode = new Node;
	newNode->data = value;
	newNode->next = head;
	head = newNode;
	cout<<"Node inserted at the beginning"<<endl;
}

void insertAtEnd(Node*& head, int value){
	Node* newNode = new Node;
	newNode->data = value;
	newNode->next = nullptr;

	if(head == nullptr){
		head = newNode;
	}
	else{
		Node* temp = head;
		while(temp->next != nullptr){
			temp = temp->next;
		}
		temp->next = newNode;
	}
	cout<<"New node created at the end"<<endl;
}

void deleteNode(Node*& head, int value){
	if( head == nullptr){
		cout<<"Empty list, Cannot delete"<<endl;
		return;
	}
	Node* temp = head;
	Node* prev = nullptr;

	while(temp != nullptr && temp->data != value){
		prev = temp;
		temp = temp->next;
	}
	if(temp == nullptr){
		cout<<"The value " <<value<<" is not present in the list"<<endl;
		return;

	}

	if(prev == nullptr){
		head = temp->next;
	}
	else{
		prev->next = temp->next;
	}

	delete temp;
	cout<<"Node deleted"<<endl;

}	

void display(Node* head){
	Node* temp = head;
	cout<<"Linked List - ";
	while(temp != nullptr){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;

}


int main(){
	Node* head = nullptr;
	int choice,value;
	while(true){
		cout<<"\n---- Menu ----"<<endl;
		cout<<"\n1. Insert at the beginning "<<endl;
		cout<<"2. Insert at the end "<<endl;
		cout<<"3. Delete a  node"<<endl;
		cout<<"4. Display the list"<<endl;
		cout<<"5. Exit the program"<<endl;
		cout<<"\nEnter your choice - ";

		if(cin>>choice){
			switch(choice){
				case 1:
					cout<<"Enter the value to be inserted - ";
					cin>>value;
					insertAtBeginning(head,value);
					break;
				case 2:
					cout<<"Enter the value to be inserted - ";
					cin>>value;
					insertAtEnd(head,value);
					break;
				case 3: 
					cout<<"Enter the value to be deleted - ";
					cin>>value;
					deleteNode(head,value);
					break;
				case 4: 
					display(head);
					break;
				case 5:
					cout<<"Exiting the program"<<endl;
					return 0;
				default:
					cout<<"!!! Invalid input !!!"<<endl;
					cin.ignore();
					break;

			}
		}
		else{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');//to avoid infinite loop if user enter string as input
			cout<<"Please enter numbers in the menu "<<endl;
		}

	}


	return 0;
}
