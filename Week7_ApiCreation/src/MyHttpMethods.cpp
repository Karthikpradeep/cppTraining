#include <MyHttpMethods.h>
#include <curl/curl.h>

MyHttpMethods::MyHttpMethods(){
	initializeCurl();
}

MyHttpMethods::~MyHttpMethods(){
	cleanupCurl();
}

void MyHttpMethods::initializeCurl(){
	curl_global_init(CURL_GLOBAL_DEFAULT);
	curlHandle = curl_easy_init();
}

void MyHttpMethods::cleanupCurl(){
	if(curlHandle){
		curl_easy_cleanup(curlHandle);
		curlHandle = nullptr;
	}
	curl_global_cleanup();
}

string MyHttpMethods::getHttp(const string& url){
	if(!curlHandle){
		return "";
	}
	curl_easy_setopt(curlHandle,CURLOPT_URL,url.c_str());

	string response;
	curl_easy_setopt(curlHandle, CURLOPT_WRITEFUNCTION, writeCallback);
    	curl_easy_setopt(curlHandle, CURLOPT_WRITEDATA, &response);
	
	CURLcode res = curl_easy_perform(curlHandle);

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
    size_t totalSize = size * noMemb;
    output->append(static_cast<char*>(contents), totalSize);
    return totalSize;
}



