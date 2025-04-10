#include "./functions.h"
#include <nlohmann/json.hpp>
using json = nlohmann::ordered_json;
using namespace std;


vector<vector<std::string>> parse_j(string json_str){
    json j = json::parse(json_str);
   
    vector<vector<string>> parsed;
    // vector<string> order;

    // if(!j.empty()){
    //     for(auto &[key,value] : j[0].items()){
    //         order.push_back(key);
    //     }
    // }

    for(auto &item : j){
        vector<string> row;
        // for(auto &col : order){ 
            // if(item.contains(col)){
                // auto &value = item[col];
            for(auto &[key, value] : item.items()){
                if(value.is_string()){
                    row.push_back(value.get<string>());
                }
                else{
                    row.push_back(value.dump());
                }
            //}
            // else{
            //     row.push_back("");
            // }
        }  
        parsed.push_back(row);
    }

    return parsed;
}

