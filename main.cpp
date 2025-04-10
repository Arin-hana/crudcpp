#include "./functions.h"
using namespace std;



int main(){

    vector<vector<string>> response;
    vector<vector<string>> sorted;

    response = parse_j(get_row_names());
    sorted = sort(response, 3);

     for(auto row : response){
        for (auto col : row){
            cout<<col<<" ";
        }
        cout<<" \n";
     }
     cout<<endl;
     
     for(auto row : sorted){
        for (auto col : row){
            cout<<col<<" ";
        }
        cout<<" \n";
     }
    // cout<<get_row_names();

return(0);
}