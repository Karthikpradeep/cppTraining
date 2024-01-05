#include<iostream>

using namespace std;

class BankAccount{
	private:
		int accountNumber;
		int balance;
		string ownerName;

	public:
		void setAccount(int accNumber){
			accountNumber = accNumber;
		}
		int getAccount(){
			return accountNumber;
		}
		void setBalance(int Balance){
			balance = Balance;
		}
		int getBalance(){
			return balance;
		}
		void setName(string name){
			ownerName = name;
		}
		string getName(){
			return ownerName;
		}

		BankAccount(int accNumber,int bala,string name){
			accountNumber = accNumber;
			balance = bala;
			ownerName = name;
		}

		void deposit(int amount){
			if(amount>0){
				balance += amount;
				cout<<"Amount of rs"<<amount<<" was credited successfully"<<endl;
			}
			else{
				cout<<"Invalid amount"<<endl;
			}
		}

		void withdraw(int amount){
			if(amount>0 && amount<=balance){
				balance -=amount;
				cout<<"Amount of rs"<<amount<<" was  debited successfully"<<endl;
			}
			else{
				cout<<"Insufficient balance"<<endl;
			}
		}

		void display(){
			cout<<"\nAccount details"<<endl;
			cout<<"Account number - "<<accountNumber<<endl;
			cout<<"Account balance - "<<balance<<endl;
			cout<<"Owner name - "<<ownerName<<endl;
		}

};

int main(){
	BankAccount myAccount = BankAccount(10111921,2000,"Karthik");
	myAccount.display();
	//myAccount.ownerName("Soorya"); since our variables are private they can't be modified outside of the class. To modify them getter and setter are used
	//myAccount.display(); by this we achieve encapsulation.
	myAccount.setName("Soorya");
	myAccount.display();
}
