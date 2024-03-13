#include <bstHeader.h>

int main(){
	BST bst;
	int choice,val;
	do{
		cout<<"---------Menu----------"<<endl;
		cout<<"1.Insertion"<<endl;
		cout<<"2.Deletion"<<endl;
		cout<<"3.Search"<<endl;
		cout<<"4.Preorder Traversal"<<endl;
		cout<<"5.Inorder Traversal"<<endl;
		cout<<"6.PostOrder Traversal"<<endl;
		cout<<"7.Exit"<<endl;
		cout<<"\n Enter your choice - ";
		cin>>choice;
		switch(choice){
			case 1:
				cout<<"Enter the value to be inserted - ";
				cin>>val;
				bst.insert(val);
				break;
			case 2:
				cout<<"Enter the value to be deleted - ";
				cin>>val;
				bst.remove(val);
				break;
			case 3:
				cout<<"Enter the value to be searched - ";
				cin>>val;
				if(bst.search(val)){
					cout<<val<<" is found in the BST."<<endl;
				}
				else{
					cout<<val<<" is not found in the BST."<<endl;
				}
				break;
			case 4:
				bst.preorder();
				break;

			case 5:
				bst.inorder();
				break;
			case 6:
				bst.postorder();
				break;
			case 7:
				cout<<"Exiting the program"<<endl;
				break;
			default :
				cerr<<"Invalid input try again"<<endl;
				break;
		}
		
	}while(choice!=7);
	return 0;
}

