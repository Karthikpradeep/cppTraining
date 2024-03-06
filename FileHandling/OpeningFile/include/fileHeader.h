#ifndef FILEHEADER_H
#define FILEHEADER_H

#include <iostream>
#include <fstream>

using namespace std;

class FileHandling{
	private :
		string fileName;
	public :
		FileHandling(const string& fileName);
		~FileHandling();
		void createFile();
};
#endif

		
