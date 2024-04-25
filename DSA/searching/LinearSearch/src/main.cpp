#include <lsHeader.h>

int main(){
	LinearSearch ls;
	int size,elem;
	cout<<"Enter the number of needed - ";
	cin>>size;
	ls.addElement(size);
	cout<<"Enter the element to be searched - ";
	cin>>elem;
	ls.search(size,elem);
	return 0;
}
