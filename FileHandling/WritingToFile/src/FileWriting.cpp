#include <fileHeader.h>

FileWriting::FileWriting(const string& FileName):FileName(FileName){
}

FileWriting::~FileWriting(){
}

void FileWriting::WritingToFile(){

	ofstream new_file;
	new_file.open(FileName,ios::out);
	if(!new_file){
		cerr<<"!!! File creation failed !!!"<<endl;
	}
	else{
		cout<<"New file created "<<endl;
		cout<<"Enter the contents to be written to the file "<<endl;
		while(getline(cin,content)){
			if( content.empty()){
				break;
			}
			data.push_back(content.append("\n"));
		}		
		for(const string& cont: data){
			new_file.write(cont.c_str(),cont.size());
		}
		//new_file<<"This is a test file "<<endl;
		//new_file<<"Writing to a file "<<endl;
		new_file.close();
	}
}

