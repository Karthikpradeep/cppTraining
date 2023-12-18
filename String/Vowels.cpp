#include <iostream>

using namespace std;

int main(){
	string str;

	cout<<"Enter the string - ";
	getline(cin, str);

	int vowel = 0;
	int consonant = 0;
	int digit = 0;
	int space = 0;

	for (int i = 0; i < str.length(); i++) {
       		 char ch = tolower(str[i]);
       		 if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            		vowel++;
       		 } 
       	         else if ((ch >= 'a' && ch <= 'z')) 
		 {
           		 consonant++;
        	 } 
	         else if (ch >= '0' && ch <= '9') 
	         {
            		digit++;
       		 } 
	         else if (ch == ' ') 
		 {
            		space++;
        	 }
   	}

    	cout << "Number of Vowels - " << vowel << endl;
    	cout << "Number of Consonants - " << consonant << endl;
    	cout << "Number of Digits - " << digit << endl;
    	cout << "Number of Spaces - " << space << endl;

	return 0;
}

