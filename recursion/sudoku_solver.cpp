#include<iostream>
#include<vector>
using namespace std;
bool isSafe(vector<vector<char>> &board, int row, int column,char digit){
    //horizontal
    for(int j=0; j<9; j++){
        if(board[row][j]==digit){
            return false;
        }
    }
    // vertical
    for(int i=0; i<9; i++){
        if(board[i][column]==digit){
            return false;
        }
    }
    //3*3 grid
    int starting_row=(row/3)*3;
    int starting_column=(column/3)*3;
    for(int i=starting_row; i<=starting_row+2; i++){
        for(int j=starting_column; j<=starting_column+2;j++){
                    if(board[i][j]==digit){
            return false;

        }
    }
    }
    return true;
}
bool Solver( vector<vector<char>> &board, int row, int column){
    int nextRow=row;
    int nextColumn=column+1;
    if(nextColumn==9){
        nextRow=row+1;
        nextColumn=0;
    }
    if(row==9){
        return true;
    }
    if(board[row][column]!= '.'){
       return Solver(board,nextRow,nextColumn);
    }
    for(char digit='1'; digit<='9'; digit++){
        if(isSafe(board,row,column,digit)){
            board[row][column]=digit;
            if(Solver(board,nextRow,nextColumn)){
                return true;
            }
            board[row][column]='.';
        }
    }
    return false;
}
int main(){
    vector<vector<char>> board = {
    {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
    {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
    {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
    {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
    {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
    {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
    {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
    {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
    {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
};
Solver(board,0,0);
    for(int i=0; i<board.size(); i++){
        cout<<"{ ";
        for(int j=0; j<board[i].size(); j++){
            cout<<board[i][j]<<" ";
        }
        cout<<"}";
        cout<<endl;
    }
    return 0;
}

/*
{ 5 3 4 6 7 8 9 1 2 }
{ 6 7 2 1 9 5 3 4 8 }
{ 1 9 8 3 4 2 5 6 7 }
{ 8 5 9 7 6 1 4 2 3 }
{ 4 2 6 8 5 3 7 9 1 }
{ 7 1 3 9 2 4 8 5 6 }
{ 9 6 1 5 3 7 2 8 4 }
{ 2 8 7 4 1 9 6 3 5 }
{ 3 4 5 2 8 6 1 7 9 }


vector<vector<char>> board = {
    {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
    {'6', '7', '.', '1', '9', '5', '.', '.', '.'},
    {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
    {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
    {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
    {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
    {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
    {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
    {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
};


*/