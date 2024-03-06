#include <fileHeader.h>

FileHandling::FileHandling(const string& fileName):fileName(fileName){
}

FileHandling::~FileHandling(){
}

void FileHandling::createFile(){

	fstream new_file;

	new_file.open(fileName,ios::out);

	if(!new_file){
		cerr<<"!!! File creation failed !!!"<<endl;
	}
	else{
		cerr<<" File successfully created"<<endl;
	}
	new_file.close();
}

