#include<iostream>
#include<map>

using namespace std;

int main(){
        map<int, string> student;
        int entries,key,searchKey;
        string value;
        cout<<"Enter the number of entries needed - ";
        cin>>entries;

        for(int i=0;i<entries;i++){
                cout<<"Enter the student roll number - ";
                cin>>key;

                cout<<"Enter the student name - ";
                cin>>value;

                student[key] = value;
        }
        map<int, string> :: iterator iter;
        for(iter=student.begin();iter != student.end();++iter){
                cout<<"Roll number - "<<iter -> first<<"\t Name - "<<iter -> second<<endl;
        }

	cout<<endl;
	return 0;
}

