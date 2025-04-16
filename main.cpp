#include "./functions.h"
#include <ncurses/ncurses.h>
using namespace std;

void sorted(vector<vector<string>> parsed, int col){
    vector<vector<string>> sorted;
    sorted = sort(parsed, col);
    
        for(vector<vector<string>>::const_iterator row = sorted.begin(); row != sorted.end(); row++){
        for(vector<string>::const_iterator col = row->begin(); col != row->end(); col++){
            string step = *col;
            printw(step.c_str());
            printw(" ");
        }
        printw("\n");
    }
    refresh();
}

int main(){

    initscr();
    clear();
    raw();

    vector<vector<string>> response;

    response = parse_j(get_row_names());
    sorted(response, 0);

    //  for(auto row : response){
    //     for (auto col : row){
    //         cout<<col<<" ";
    //     }
    //     cout<<" \n";
    //  }
    //  cout<<endl;
    // cout<<get_row_names();
    


    refresh();
    getch();
    endwin();

    return(0);
}