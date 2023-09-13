//THIS PROGRAM TEACHS HOW TO CALL HTTP REQUEST WITH CURL
//FOLLOW THIS TUTORIAL https://www.youtube.com/watch?v=q_mXVZ6VJs4&ab_channel=TroubleChute
//INSTALL MTC IN VISUAL STUDIO INSTALLER
//AND CHECK THE ADDITIONAL LIBRARYS IT WILL BE NEEDED


#define CURL_STATICLIB
#include <string>
#include <iostream>

#include <curl/curl.h>


static size_t WriteCallback(char* contents, size_t size, size_t nmemb, char* buffer_in) {
	((std::string*)buffer_in)->append((char*)contents, size * nmemb);
	return size * nmemb;
}

PCWSTR getPassword() {
	PCWSTR a = L"FUNCIONA";
	CURL* curl;

	CURLcode res;
	std::string readBuffer;

	curl = curl_easy_init();
	if (curl) {
		curl_easy_setopt(curl, CURLOPT_URL, "http://localhost:5000/api/yourURL");
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);

		std::cout << readBuffer << std::endl;
	}
	return a;
}


int main() {
	
	getPassword();
	
	return 0;
}



