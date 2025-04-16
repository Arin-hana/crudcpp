#include "./functions.h"
#include <nlohmann/json.hpp>
using json = nlohmann::ordered_json;
using namespace std;


vector<vector<std::string>> parse_j(string json_str){
    json j = json::parse(json_str);
   
    vector<vector<string>> parsed;

    try {
        if(!j.empty()){
            for(auto &item : j){
                vector<string> row;
                for(auto &[key, value] : item.items()){
                    if(value.is_string()){
                        row.push_back(value.get<string>());
                    }
                    else{
                        row.push_back(value.dump());
                    }
                }
                parsed.push_back(row);
            }  
        }
    }
    catch(const json::exception &e){
        return {{e.what()}};
    }

    return parsed;
}

