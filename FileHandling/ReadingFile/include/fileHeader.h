#ifndef FILEHEADER_H
#define FILEHEADER_H

#include <iostream>
#include <fstream>

using namespace std;

class FileReader{
	private :
		 string fileName;
		 string line;
	public :
		 FileReader(const string& fileName);
		 ~FileReader();
		 void ReadingFile();
};
#endif


