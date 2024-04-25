#ifndef DLLHEADER_H
#define DLLHEADER_H

#include <iostream>
#include <limits>

using namespace std;

struct Node{
	int data;
	Node* next;
	Node* prev;
};

class DLL{
	private:
		void insertAtBeginning(Node*& head,int value);
		void insertAtEnd(Node*& head,int value);
		void deleteNode(Node*& head,int value); 
	public:
		DLL();
		~DLL();
		void push_front(Node*& head, int value);
		void push_back(Node*& head, int value);
		void removeNode(Node*& head, int value);
		void display(Node* head);
};
#endif
