#include<iostream>
#include<stack>

using namespace std;

int main(){
	stack<string> names;
	string name;
	cout<<"Enter the names and type exit to stop - "<<endl;
	//Inserting elements to a stack
	while(true){
		cout<<"\nEnter name - ";
		getline(cin, name);
		if(name == "exit"){
			break;
		}
		else{
			names.push(name);
		}
	}	
	//printing the top most element of a stack
	cout<<"Top element of the stack is - "<<names.top()<<endl;
	
	//removing top element of the stack
	cout<<"Removing top element of the stack "<<endl;
	names.pop();
	cout<<"Top element of stack after poping - "<<names.top()<<endl;
	
	//checking if the stack is empty
	int isEmpty = names.empty();// if retured 1 means true ie stack is empty
	if(isEmpty == 1){
		cout<<"Stack is empty"<<endl;
	}
	else{
		cout<<"Stack is not empty"<<endl;
	}
	
	//checking the size of the stack
	cout<<"Size of the stack is - "<<names.size()<<endl;



	return 0;
}

