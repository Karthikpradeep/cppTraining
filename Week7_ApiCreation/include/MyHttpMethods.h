#ifndef MYHTTPMETHODS_H
#define MYHTTPMETHODS_H

#include <iostream>
#include <string>

using namespace std;

class MyHttpMethods{

	public:
		MyHttpMethods();	//constructor
		~MyHttpMethods();	//destructor
		string getHttp(const string& url);	//method to make a get request
		string postHttp(const string& url, const string& data);	// method to make a post request
	private:
		void initializeCurl();	//inititalize libcurl library
		void cleanupCurl();	//cleaning up resources used by libcurl

		static size_t writeCallback(void* contents, size_t size, size_t noMemb, string* output);//append data to string
		void* curlHandle;	//Hold a handle for libcurl

};

#endif
