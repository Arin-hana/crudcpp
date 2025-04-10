#include "./functions.h"
#include <curl/curl.h>
using namespace std;

CURL* curl;
CURLcode res;


size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp){
    size_t totalSize = size * nmemb;
    std::string* output = static_cast<std::string*>(userp);
    output->append(static_cast<char*>(contents), totalSize);
    return totalSize;
}

void curl_start(){
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
}

void curl_clean(){
    if (curl){
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
}

string get_row_names(){
    string response;
    curl_start();
    if(curl){
        curl_easy_setopt(curl, CURLOPT_URL, "http://localhost/server/list_data.php");
        curl_easy_setopt(curl, CURLOPT_CAINFO, "./cacert.pem");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        res = curl_easy_perform(curl);
        if(res != CURLE_OK){
            cerr<<"perform failed "<<curl_easy_strerror(res);
        }
    }
    curl_clean();
    return response;
}