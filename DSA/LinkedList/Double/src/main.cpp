#include <DLLHeader.h>


int main(){
	Node* head = nullptr;
	DLL  dll;
	int choice,value;
	while(true){
		cout<<"\n--------------Menu------------------"<<endl;
		cout<<"1. Insert at the beginning of the DLL"<<endl;
		cout<<"2. Insert at the end of the DLL "<<endl;
		cout<<"3. Delete a node "<<endl;
		cout<<"4. Display the list"<<endl;
		cout<<"5. Exit"<<endl;
		cout<<"\nEnter your choice - ";

		if(cin>>choice){
			switch(choice){
				case 1:
					cout<<"Enter the value to be inserted - ";
					cin>>value;
					dll.push_front(head,value);
					break;
				case 2:
					cout<<"Enter the value to be inserted - ";
					cin>>value;
					dll.push_back(head,value);
					break;
				case 3:
					cout<<"Enter the value to be deleted - ";
					cin>>value;
					dll.removeNode(head,value);
					break;
				case 4:
					dll.display(head);
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

