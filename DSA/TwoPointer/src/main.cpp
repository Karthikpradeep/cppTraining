#include <twoHeader.h>

int main(void){
	TwoPointer tp;
	while(true){
		int val;
		cout<<"Enter the heights and type -1 to stop - ";
		cin>>val;
		if(val == -1){
			break;
		}
		else{
			tp.addHeight(val);
		}
	}

	cout<<"Max water level - "<<tp.mostWater()<<endl;
}


