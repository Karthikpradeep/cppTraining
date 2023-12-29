#include <iostream>

using namespace std;

int stringComparison(string string1, string string2){
	char* ptr1 = &string1[0];
	char* ptr2 = &string2[0];
	int count1=0,count2=0;
	while( *ptr1 != '\0'){
		count1++;
		*ptr1++;
	}
	while( *ptr2 != '\0'){
		count2++;
		*ptr2++;
	}
	if(count1>count2){
		return 0;
	}
	else if(count1<count2){
		return 1;
	}
	else{
		return 2;
	}

}

int main(){
	string string1,string2;
	cout<<"Enter the string1 - ";
	getline(cin, string1);
	cout<<"Enter the string2 - ";
	getline(cin, string2);

	int stringRelation = stringComparison(string1,string2);
	if(stringRelation == 0){
		cout<<"The string "<<string1<<" is greater than the string "<<string2<<endl;
	}
	else if(stringRelation == 1){
		cout<<"The string "<<string1<<" is less than the string "<<string2<<endl;
	}
	else{
		cout<<"The string "<<string1<<" and string "<<string2<<" are of same length"<<endl;
	}

	return 0;
}
