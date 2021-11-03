#include <iostream>
#include <string>
#include <curl/curl.h>


static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

int do_curl(std::string my_url)
{
  CURL *curl;
  CURLcode res;
  std::string readBuffer;

  curl = curl_easy_init();
  if(curl) {
   	std::cout << std::endl << "<<<<<<<<<<<<<<<<<<<<<<<" << std::endl;

    curl_easy_setopt(curl, CURLOPT_URL, my_url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

    res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);

    std::cout << readBuffer << std::endl;

    	std::cout << "<<<<<<<<<<<<<<<<<<<<<<<" << std::endl;
  }

  return 0;
}