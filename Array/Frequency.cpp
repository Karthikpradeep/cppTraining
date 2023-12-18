#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int size;

	cout<<"Enter the size of the array - ";
	cin>>size;

	int arr[size];

	cout<<"Enter the elements of the array "<<endl;
	for(int i=0;i<size;i++){
		cin>>arr[i];
	}
	sort(arr, arr+size);
	int currentElement = arr[0];
    	int currentCount = 1;
	cout<<"Occurences of each element is "<<endl;
	for (int i = 1; i < size; i++) {
        	if (arr[i] == currentElement) {
            		currentCount++;
       		} 
		else {
        	    cout << "Element " << currentElement << ": " << currentCount << " times\n";
        	    currentElement = arr[i];
        	    currentCount = 1;
       		}

        }
	cout << "Element " << currentElement << ": " << currentCount << " times\n";
	return 0;
}

