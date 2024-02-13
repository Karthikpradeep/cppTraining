#include<MyHttpMethods.h>

int main(){
	MyHttpMethods httpClient;

	//get request
	
	string getUrl;
	cout<<"Enter the url for GET request- ";
	getline(cin,getUrl);
	string getResponse = httpClient.getHttp(getUrl);
	cout<<"GET response is - "<<getResponse<<endl;
	
	//post request
	string postUrl;
	cout<<"Enter the url for POST request - ";
	getline(cin, postUrl);
	cout<<"\nEnter the post data - ";
	string postData;
	getline(cin, postData);

	string postResponse = httpClient.postHttp(postUrl, postData);
	cout<<"POST response is - "<<postResponse<<endl;

	return 0;
}

