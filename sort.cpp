#include "./functions.h"
using namespace std;

bool is_num(std::string &from_parsed){
    return !from_parsed.empty() && (count_if(from_parsed.begin(), from_parsed.end(), [](char dot){return isdigit(dot) || dot=='.';}) == from_parsed.size());
}

bool is_int(std::string &from_parsed){
    return !from_parsed.empty() && (count_if(from_parsed.begin(), from_parsed.end(), ::isdigit) == from_parsed.size());
}

bool is_date(const std::string& str) {
    return regex_match(str, regex(R"(\d{4}-\d{2}-\d{2})"));
}

vector<vector<string>> sort(vector<vector<string>> &parsed,int column){
    int rowsize = parsed.size();

    for(int table_sort = 0; table_sort < rowsize - 1; table_sort++){
        for(int row =0; row < rowsize - 1 - table_sort; row++){
            if(is_int(parsed[row][column])){
                if(stoi(parsed[row][column]) > stoi(parsed[row+1][column])){
                    swap(parsed[row], parsed[row+1]);
                }
            }
            else if(is_num(parsed[row][column])){
                if(stof(parsed[row][column]) > stof(parsed[row+1][column])){
                    swap(parsed[row], parsed[row+1]);
                }
            }
            else if(is_date(parsed[row][column])){
                if((parsed[row][column]) > (parsed[row+1][column])){
                    swap(parsed[row], parsed[row+1]);
                }
            }
            else{
                swap(parsed[row], parsed[row+1]);
            }
        }
    }
    return parsed;
}