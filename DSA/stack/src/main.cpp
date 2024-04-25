#include <stackHeader.h>

int main(){
	Node* top = nullptr;
	Stack stk;
	int choice,value;
	while(true){
		cout<<"--------------Menu--------------"<<endl;
		cout<<"1. Push"<<endl;
		cout<<"2. Pop"<<endl;
		cout<<"3. Top"<<endl;
		cout<<"4. Exit"<<endl;
		cout<<"\nEnter your choice - ";
		if(cin>>choice){
			switch(choice){
				case 1:
					cout<<"Enter the element to push - ";
					cin>>value;
					stk.push(top,value);
					break;
				case 2:
					stk.pop(top);
					break;
				case 3:
					stk.topNode(top);
					break;
				case 4:
					cout<<"Exiting the program"<<endl;
					exit(0);
				default:
					cout<<"!!! Wrong input !!!"<<endl;
					break;
			}
		}
		else{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			cout<<"Please enter the inputs from menu"<<endl;
		}
	}
	return 0;
}

