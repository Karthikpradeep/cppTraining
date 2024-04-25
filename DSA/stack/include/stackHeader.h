#ifndef STACKHEADER_H
#define STACKHEADER_H

#include <bits/stdc++.h>

using namespace std;

struct Node{
	int data;
	Node* next;
};

class Stack{
	private:
		void insertNode(Node*& top,int value);
		void removeNode(Node*& top);
		void firstNode(Node*& top);
	public:
		Stack();
		~Stack();
		void push(Node*& top,int value);
		void pop(Node*& top);
		void topNode(Node*& top);
};
#endif

