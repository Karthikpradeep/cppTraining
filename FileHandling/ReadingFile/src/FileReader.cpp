#include <fileHeader.h>

FileReader::FileReader(const string& fileName):fileName(fileName){
}

FileReader::~FileReader(){
}

void FileReader::ReadingFile(){
	
	ifstream file;
	file.open(fileName);
	if(!file){
		cerr<<"!!! Error while opening file !!!"<<endl;
	}
	else{
		cout<<"Reading from the file\n"<<endl;
		cout<<"Contents of the file are - "<<endl;
		
		while(file.good()){
			getline(file,line);
			cout<<line<<endl;
		}
	}
	file.close();
}
