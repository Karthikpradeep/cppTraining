#include<iostream>
#include<set>

using namespace std;

int main(){
	set<int> mySet1;
        int size,num;
        cout<<"Enter the size of the set1 - ";
        cin>>size;

        cout<<"Enter the elements to the set1 "<<endl;
        for(int i=0;i<size;i++){
                cout<<"Element "<<i+1<<" - ";
                cin>>num;
                mySet1.insert(num);
        }
        cout<<"Elements of the set1 are - ";
        for(int i : mySet1){
                cout<<i<<" ";
        }
	set<int> mySet2;
        cout<<"\nEnter the size of the set2 - ";
        cin>>size;

        cout<<"Enter the elements to the set2 "<<endl;
        for(int i=0;i<size;i++){
                cout<<"Element "<<i+1<<" - ";
                cin>>num;
                mySet2.insert(num);
        }
        cout<<"Elements of the set2 are - ";
        for(int i : mySet2){
                cout<<i<<" ";
        }
	set<int> intersection;
	cout<<"\nIntersection of sets are - ";
	for(int i : mySet1){
		if(mySet2.count(i)>0){
			intersection.insert(i);
		}
	}
	for(int i : intersection){
		cout<<i<<" ";
	}
	cout<<endl;

	return 0;
}
	
