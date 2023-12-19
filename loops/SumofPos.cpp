#include <iostream>

using namespace std;

int main(){
	int num = 1,sum = 0;
        while(num>0){
                
                cout<<"Enter the number - ";
                cin>>num;
		if(num<0){
			break;
		}
		else{
                	sum+=num;
		}

                cout<<"Sum of numbers is - "<<sum<<endl;
        }

        return 0;
}

