#include <iostream>

using namespace std;

void stringConcat(char str1[],char str2[]){
	char* ptr1 = &str1[0];
	char* ptr2 = &str2[0];
	while( *ptr1 != '\0'){
		*ptr1++;
	}
	while(*ptr2 != '\0'){
		*ptr1=*ptr2;
		*ptr1++;
		*ptr2++;
	}
	*ptr1='\0';
	cout<<str1<<endl;

}
int main(){
	char str1[50], str2[50];
	cout<<"Max character of 50 enter the strings"<<endl;
	cout<<"Enter the string1 - ";
	cin>>str1;
	cout<<"Enter the string2 - ";
        cin>>str2;
	stringConcat(str1,str2);
									
	return 0;
}

