#include "./functions.h"
using namespace std;



int main(){

    vector<vector<string>> response;

    response = parse_j(get_row_names());


    // cout<<response;

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
     for(auto row : response){
        for (auto col : row){
            cout<<col<<" ";
        }
        cout<<" \n";
     }
    // cout<<get_row_names();

return(0);
}