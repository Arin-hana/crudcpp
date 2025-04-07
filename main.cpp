#include <iostream>
#include <fstream>
#include "./functions.h"
#include <nlohmann/json.hpp>
#include <curl/curl.h>
using namespace std;
using json = nlohmann::json;

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp){
    size_t totalSize = size * nmemb;
    std::string* output = static_cast<std::string*>(userp);
    output->append(static_cast<char*>(contents), totalSize);
    return totalSize;
}

int main(){
    ifstream file("table.json");
    if(!file){
        return 1;
    }
    json data;
    file >> data;

    CURL* curl;
    CURLcode res;
    string response;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl){
        curl_easy_setopt(curl, CURLOPT_URL, "http://localhost/server/list_rows.php");
        // curl_easy_setopt(curl, CURLOPT_CAINFO, "./cacert.pem");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        res = curl_easy_perform(curl);
        if(res != CURLE_OK){
            cerr<<"perform failed "<<curl_easy_strerror(res);
        }
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    cout<<response;

    // int sizeofrow = sizeof(table)/sizeof(table[0]);
    // // cout<<sizeof(table)/sizeof(table[0]);
    // cout<<"data\n";
    // for(int row = 0; row < sizeofrow; row++){
    //     for (int col = 0; col < 4; col++){
    //         cout<<table[row][col]<<" ";
    //     }
    //     cout<<" \n";
    // }
    // cout<<"sorted\n";
    // sort(table,sizeofrow, 0);
    // for(int row = 0; row < sizeofrow; row++){
    //     for (int col = 0; col < 4; col++){
    //         cout<<table[row][col]<<" ";
    //     }
    //     cout<<" \n";
    // }

return(0);
}