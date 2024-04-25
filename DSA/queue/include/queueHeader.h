#ifndef QUEUEHEADER_H
#define QUEUEHEADER_H

#include <bits/stdc++.h>

using namespace std;

struct Node{
	int data;
	Node* next;
};

class Queue{
	private:
		void push(Node*& front,Node*& rear,int value);
		void pop(Node*& front,Node*& rear);
	public:
		Queue();
		~Queue();
	       	void enqueue(Node*& front,Node*& rear,int value);
		void dequeue(Node*& front,Node*& rear);
		void first(Node* front);
		void last(Node* rear);
		void display(Node* front);
};
#endif
