// AI/FETCH/CURL.CPP - USED BY "AI/AI.H"
    // do_curl(string url) && fetch_links(string url, int limit)

#include <iostream>
#include <string>
#include <curl/curl.h>

#include <fstream>

char *URLS[1024];
bool URLS_isset = false;


static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {   // callback function
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

int do_curl(std::string my_url) {   // does the curl function
    CURL *curl;
    CURLcode res;
    std::string readBuffer;
    std::string filen = "bay/downloads/page.html";

    std::ofstream outfile;
    outfile.open(filen);

    curl = curl_easy_init();
    
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, my_url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
   	
        std::cout << std::endl << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << std::endl << std::endl;
        std::cout << readBuffer;    // prints the curled page.
        std::cout << std::endl << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << std::endl;

        // store HTML file
        if (outfile.is_open() == true) {
            outfile << readBuffer;
            outfile.close();
            
            std::cout << "~:: file stored at : \"" << filen << "\"." << std::endl;
        }
    }
return 0;
}

int fetch_link(std::string &my_url, int max_links)  // fetches links
{
    CURL *curl;
    CURLcode res;
    std::string readBuffer;

    //bool hit = false;
    
    bool http = false;
    bool https = false;

    int remainder;
    int httpcount = 0;
    int httpscount = 0;

    std::string ourprot="";

    curl = curl_easy_init();
    if(curl) {

        curl_easy_setopt(curl, CURLOPT_URL, my_url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
   	

        // std::cout << readBuffer << std::endl;
            // FETCH LINKS FROM "readBuffer"

        std::cout << "~:: analyzing input: (readBuffer)" << std::endl;

        std::cout << std::endl << "<<<<<<<<<<<<<<<<<<<<<<<" << std::endl;
        for (std::string::size_type i = 0, j = 0; i < my_url.size(); i++) {
            // iterate string
        
            // find http
            // find https
            // find ftp
            // find www
            
            std::cout << my_url[i];
            if (my_url.length()-i > 8 && my_url[i] == 'h' && my_url[i+1] == 't' && my_url[i+2] == 't' && my_url[i+3] == 'p') {
                
                if (my_url.length()-i > 7 && my_url[i+4] == ':' && my_url[i+5] == '/' && my_url[i+6] == '/') {
                    http=true;
                    remainder = my_url.length() - i;

                    std::cout << "\t -/- found link (index + " << i << "): ";

                } else if (my_url.length()-i > 8 && my_url[i+4] == 's' && my_url[i+5] == ':' && my_url[i+6] == '/' && my_url[i+7] == '/') {
                    https=true;
                    remainder = my_url.length() - i;

                    std::cout << "\t -/- found link (index + " << i << "): ";

                }

                if (http == true) {
                    ourprot = "http";
                    httpcount++;
                }

                if (https == true) {
                    ourprot = "https";
                    httpscount++;
                }

            }
            
            //std::cout << "\t" << ourprot << std::endl;
        }
   	    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<" << std::endl;
    }
return 0;
};

// eof