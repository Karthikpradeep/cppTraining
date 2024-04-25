#include <binaryHeader.h>

int main(){
	BinarySearch bs;
	int size,element;
	cout<<"Enter the number of elements - ";
	cin>>size;
	bs.addElement(size);
	cout<<"Enter the element to be searched - ";
	cin>>element;
	bs.search(size,element);
	return 0;
}
