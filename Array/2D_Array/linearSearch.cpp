#include<iostream>
using namespace std;
void LinearSearch(int matrix[][3], int rows, int columns, int key,   pair<int,int> &cell){
        for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            if(matrix[i][j]==key){
                 cell={i,j};
                 return ;
            }
        }
    }
    cell={-1,-1};
}
int main(){
    int matrix[2][3]={{1,2,3},{4,5,6}};
    int rows=2;
    int columns=3;
    int key=7;
    pair<int,int> cell;
    LinearSearch(matrix,rows, columns, key, cell);
    cout<<cell.first<<","<<cell.second;
    return 0;
}