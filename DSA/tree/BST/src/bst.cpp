#include <bstHeader.h>

BST::BST(){
	root = nullptr;
}

Node* BST::createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}


Node* BST::insert(Node* root,int val){
	if(root == nullptr){
		return createNode(val);
	}
	if(val < root->data){
		root->left = insert(root->left,val);
	}
	else{
		root->right = insert(root->right,val);
	}
	return root;
}

void BST::insert(int val){
	root = insert(root,val);
}

bool BST::search(Node* root,int val){
	if(root == nullptr){
		return false;
	}
	if(root->data == val){
		return true;
	}
	else if(val < root->data){
		return search(root->left,val);
	}
	else{
		return search(root->right,val);
	}
}

bool BST::search(int val){
	return search(root,val);
}

Node* BST::minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

Node* BST::deleteNode(Node* root, int val) {
    if (root == nullptr) {
        return root;
    }
    if (val < root->data) {
        root->left = deleteNode(root->left, val);
    } else if (val > root->data) {
        root->right = deleteNode(root->right, val);
    } else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void BST::remove(int val) {
    root = deleteNode(root, val);
}

void BST::preOrder(Node* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void BST::preorder(){
	cout<<"BST in preorder traversal - ";
	preOrder(root);
	cout<<endl;
}

void BST::inOrder(Node* root) {
    if (root == nullptr) {
        return;
    }
    inOrder(root->left);
    cout << root->data <<" ";
    inOrder(root->right);
}

void BST::inorder(){
	cout<<"BST in inorder traversal - ";
	inOrder(root);
	cout<<endl;
}

void BST::postOrder(Node* root) {
    if (root == nullptr) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
    
}

void BST::postorder(){
	cout<<"BST in postorder traversal - ";
	postOrder(root);
	cout<<endl;
}

