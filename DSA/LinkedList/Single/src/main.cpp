#include <singleLLHeader.h>

int main(){
	Node* head = nullptr;
	SinglyLinked  sl;
	int choice,value;
	while(true){
		cout<<"\n--------------Menu------------------"<<endl;
		cout<<"1. Insert at the beginning of the LL"<<endl;
		cout<<"2. Insert at the end of the LL "<<endl;
		cout<<"3. Delete a node "<<endl;
		cout<<"4. Display the list"<<endl;
		cout<<"5. Exit"<<endl;
		cout<<"\nEnter your choice - ";

		if(cin>>choice){
			switch(choice){
				case 1:
					cout<<"Enter the value to be inserted - ";
					cin>>value;
					sl.insertAtFront(head,value);
					break;
				case 2:
					cout<<"Enter the value to be inserted - ";
					cin>>value;
					sl.insertAtRear(head,value);
					break;
				case 3:
					cout<<"Enter the value to be deleted - ";
					cin>>value;
					sl.removeNode(head,value);
					break;
				case 4:
					sl.display(head);
					break;
				case 5:
					cout<<"Exiting program"<<endl;
					exit(0);
				default:
					cout<<"!!! Wrong input. Try again !!!"<<endl;
					break;
			}
		}
		else{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			cout<<"Please enter the number in the menu "<<endl;
		}
	}
	return 0;
}


