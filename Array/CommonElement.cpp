#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

int main(){
	int num;

	cout<<"Enter the number of arrays - ";
	cin>>num;

	int arr[num][20];
	int len[num];
	for(int i=0;i<num;i++){
		int size;

		cout<<"Enter the size of Array "<<i+1<<" - ";
		cin>>size;
		len[i]=size;
		for(int j=0;j<size;j++){
			cout<<"Element "<<j+1<<" - ";
			cin>>arr[i][j];
		}
	}
	for (int i = 0; i < num; i++) {
        	cout << "Array " << i + 1 << ": ";
        	for (int j = 0; j < len[i]; j++) {
            		cout << arr[i][j] << " ";
        	}
        	cout << endl;
   	}

	unordered_set<int> commonElements;

        for (int j = 0; j < len[0]; j++) {
        int currentElement = arr[0][j];
        bool isCommon = true;

        for (int i = 1; i < num; i++) {
            if (find(arr[i], arr[i] + len[i], currentElement) == arr[i] + len[i]) {
                isCommon = false;
                break;
            }
        }
       	 if (isCommon) {
        	 commonElements.insert(currentElement);
       	         }
        }
        cout << "Common elements: ";
    	for (int element : commonElements) {
       		 cout << element << " ";
   	 }
   	 cout << endl;

	return 0;
}



