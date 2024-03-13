#ifndef BSTHEADER_H
#define BSTHEADER_H

#include <iostream>

using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;
};

class BST{
	private:
		Node* root;
		Node* createNode(int data);
		Node* insert(Node* root,int val);
		bool search(Node* root, int val);
		Node* minValueNode(Node* node);
		Node* deleteNode(Node* root,int val);
		void preOrder(Node* root);
		void inOrder(Node* root);
		void postOrder(Node* root);

	public:
		BST();
		void insert(int val);
		bool search(int val);
		void remove(int val);
		void preorder();
		void inorder();
		void postorder();
};
#endif

