#include <iostream>
#include <fstream>
#include "./functions.h"
#include "./json.hpp"
using namespace std;
using json = nlohmann::json;
int main(){
    ifstream file("table.json");
    if(!file){
        return 1;
    }
    json data;
    file >> data;


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