#ifndef SINGLELLHEADER_H
#define SINGLELLHEADER_H

#include <iostream>
#include <limits>

using namespace std;

struct Node{
	int data;
	Node* next;
};

class SinglyLinked{
	private:
		void insertAtBeginning(Node*& head, int value);
		void insertAtEnd(Node*& head, int value);
		void deleteNode(Node*& head, int value);
	public:
		SinglyLinked();
		~SinglyLinked();
		void insertAtFront(Node*& head, int value);
		void insertAtRear(Node*& head, int value);
		void removeNode(Node*& head, int value);
		void display(Node* head);
};

#endif

