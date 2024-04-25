#ifndef LSHEADER_H
#define LSHEADER_H

#include <iostream>

using namespace std;

class LinearSearch{
	private:
	       	int* arr;	
		int element;
		int flag;
	public:
		LinearSearch();
		~LinearSearch();
		void addElement(int size);
		void search(int size,int element);
};

#endif
