#include<iostream>
using namespace std;
#include<vector>
bool isSafe(vector<string> &board, int row, int column, int n){
    //row
for(int j=0; j<n; j++){
    if(board[row][j]=='Q'){
        return false;
    }
}
//column
for(int i=0; i<n; i++){
    if(board[i][column]=='Q'){
        return false;
    }
}
//leftdiagonal 
for(int i=row, j=column; i>=0 &&j>=0; i--,j--){
    if(board[i][j]=='Q'){
        return false;
    }
}
//rightdiagonal 
for(int i=row, j=column; i>=0 &&j<n; i--,j++){
    if(board[i][j]=='Q'){
        return false;
    }
}
return true;
}
void nQueens(vector<string> &board, int row, int n,  vector<vector<string>> &ans){
    if(row==n){
        ans.push_back({board});
        return;
    }
    for(int j=0; j<n; j++){
        if(isSafe(board,row,j,n)){
            board[row][j]='Q';                                                                                                                            
            nQueens(board,row+1,n,ans);
            board[row][j]='.';
        }
    }
}
 vector<vector<string>>  SolveNqueen(int n){
    vector<string> board (n,string(n,'.'));
    vector<vector<string>> ans;
    nQueens(board,0,n,ans);
    return ans;
 }

int main(){
    int n=4;
    vector<vector<string>> print=SolveNqueen(n);
    for(int i=0; i<print.size(); i++){
        for(int j=0; j<print[i].size(); j++){
            cout<<print[i][j]<<" ";
        }
        cout<<endl;
    }
    //[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
    return 0;
}