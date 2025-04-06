#include "./functions.h"
using namespace std;
void sort(std::string table[][4],int rowsize, int column){
    for(int table_sort = 0; table_sort < rowsize - 1; table_sort++){
        for(int row =0; row < rowsize - 1 - table_sort; row++){
            if(column == 0){
                if(stoi(table[row][column]) > stoi(table[row+1][column])){
                    for(int col =0; col <4; col++){
                        swap(table[row][col], table[row+1][col]);
                    }
                }
            }
            else{
                if(table[row][column] > table[row+1][column]){
                    for(int col =0; col <4; col++){
                        swap(table[row][col], table[row+1][col]);
                    }
                }
            }
        }
    }
}