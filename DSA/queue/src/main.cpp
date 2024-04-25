#include <queueHeader.h>

int main(){
        Node* front = nullptr;
        Node* rear = nullptr;
	Queue qu;
        int choice,value;
        while(true){
                cout<<"--------------Menu--------------"<<endl;
                cout<<"1. Enqueue"<<endl;
                cout<<"2. Dequeue"<<endl;
                cout<<"3. Front"<<endl;
                cout<<"4. Rear"<<endl;
		cout<<"5. Display"<<endl;
		cout<<"6. Exit"<<endl;
                cout<<"\nEnter your choice - ";
                if(cin>>choice){
                        switch(choice){
                                case 1:
                                        cout<<"Enter the element to push - ";
                                        cin>>value;
                                        qu.enqueue(front,rear,value);
                                        break;
                                case 2:
                                        qu.dequeue(front,rear);
                                        break;
                                case 3:
                                        qu.first(front);
                                        break;
				case 4:
					qu.last(rear);
					break;
				case 5:
					qu.display(front);
					break;
                                case 6:
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
	
