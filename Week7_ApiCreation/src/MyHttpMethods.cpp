#include <MyHttpMethods.h>
#include <curl/curl.h>

MyHttpMethods::MyHttpMethods(){	//This is the constructor implementation.
	initializeCurl();//Initialize lib curl
}

MyHttpMethods::~MyHttpMethods(){//Destructor implementation
	cleanupCurl();//Cleanup resources 
}

void MyHttpMethods::initializeCurl(){
	curl_global_init(CURL_GLOBAL_DEFAULT);//initialize libcurl library globally->to setup global options for libcurl
	curlHandle = curl_easy_init();//Initialize a new easy handle. Easy handle is an interface to perform simple and synchronous HTTP req
       	//curl_easy_init allocate and initialize a new easy handle,returning a pointer to it. Handle is used to set various option such as
	// the url, request type and call back function before performing actual http request.	
}

void MyHttpMethods::cleanupCurl(){
	if(curlHandle){
		curl_easy_cleanup(curlHandle);//clean up and free resources associated with an easy handle;
		curlHandle = nullptr;
	}
	curl_global_cleanup();//clean up the global resources
}

string MyHttpMethods::getHttp(const string& url){
	if(!curlHandle){
		return "";
	}
	//curl_easy_setopt tell libcurl how to behave
	curl_easy_setopt(curlHandle,CURLOPT_URL,url.c_str());//set url for http request. Parameter is the url as c string

	string response;//variable to store http response from the server
	curl_easy_setopt(curlHandle, CURLOPT_WRITEFUNCTION, writeCallback);//set writeCallback function that libcurl will invoke to handle the	      received data during HTTP request. It append received data to response string
    	curl_easy_setopt(curlHandle, CURLOPT_WRITEDATA, &response);//user data will be passed to writecallfun. 
	
	CURLcode res = curl_easy_perform(curlHandle);//function that perform http request ie carry out the transfer and interact with server

	if(res != CURLE_OK){
		return "";
	}

	return response;
}

string MyHttpMethods::postHttp(const string& url, const string& data){
		
	if(!curlHandle){
		return "";
	}

	curl_easy_setopt(curlHandle, CURLOPT_URL, url.c_str());
    	curl_easy_setopt(curlHandle, CURLOPT_POSTFIELDS, data.c_str());

    	string response;
    	curl_easy_setopt(curlHandle, CURLOPT_WRITEFUNCTION, writeCallback);
    	curl_easy_setopt(curlHandle, CURLOPT_WRITEDATA, &response);

    	CURLcode res = curl_easy_perform(curlHandle);

    	if (res != CURLE_OK) {
        	return "";
    	}

	return response;
}

size_t MyHttpMethods::writeCallback(void* contents, size_t size, size_t noMemb, string* output) {
    size_t totalSize = size * noMemb;//calculate the total size of received data
    output->append(static_cast<char*>(contents), totalSize);//append the received data to output string
    return totalSize;
}



