#include <iostream>

using namespace std;

int main(){
	int day;

	bool check = true;
	
	while(check){
		cout<<"Enter the day of the week - ";
		cin>>day;

		if(day<1 || day>7){
			cout<<"!!! Please enter valid day of the week !!!"<<endl;
		}
		else{
			check = false;
		}
	}
	switch(day){
		case 1 :
			cout<<"Sunday"<<endl;
			break;
		case 2 :
			cout<<"Monday"<<endl;
			break;
		case 3 :
			cout<<"Tuesday"<<endl;
			break;
		case 4 :
			cout<<"Wednesday"<<endl;
			break;
		case 5 :
			cout<<"Thursday"<<endl;
			break;
		case 6 :
			cout<<"friday"<<endl;
			break;
		case 7 :
			cout<<"Saturday"<<endl;
			break;
		}

	return 0;
}

