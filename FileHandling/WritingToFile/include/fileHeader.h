#ifndef FILEHEADER_H
#define FILEHEADER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>


using namespace std;

class FileWriting{
	private :
		 string FileName;
		 string content;
		 vector<string> data;
	public :
		FileWriting(const string& FileName);
		~FileWriting();
		void WritingToFile();
};
#endif
