#include<iostream>
#include<vector>
using namespace std;
void Helper(vector<vector<int>> &matrix, int row, int column, string path, vector<string> &ans){
    int n=matrix.size();
    if(row<0 || column<0 || row>=n || column>=n || matrix[row][column]==0 || matrix[row][column]==-1){
        return;
    }
    if(row==n-1 && column==n-1){
        ans.push_back(path);
        return;
    }
    matrix[row][column]=-1;// visit
    Helper(matrix,row+1, column,path+"D",ans);//down
    Helper(matrix,row-1, column,path+"U",ans);//up
    Helper(matrix,row, column-1,path+"L",ans);//left
    Helper(matrix,row, column+1,path+"R",ans);//right
    matrix[row][column]=1;//unvisit
    
}
vector<string> FindPath(vector<vector<int>> matrix){
    int n =matrix.size();
    string path="";
    vector<string> ans;
    Helper(matrix,0,0,path,ans);
    return ans;
}
int main(){
    vector<vector<int>> matrix={{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
    vector<string> ans=FindPath(matrix);
    for(string path: ans){
        cout<<path<<endl;
    }
return 0;
}







/*
void Helper(vector<vector<int>> &matrix, int row, int column, string path, vector<string> &ans,vector<vector<bool>> &visited){
    int n=matrix.size();
    if(row<0 || column<0 || row>=n || column>=n || matrix[row][column]==0 || visited[row][column]==true){
        return;
    }
    if(row==n-1 && column==n-1){
        ans.push_back(path);
        return;
    }
    visited[row][column]=true;// visit
    Helper(matrix,row+1, column,path+"D",ans,visited);//down
    Helper(matrix,row, column+1,path+"R",ans,visited);//right
    Helper(matrix,row-1, column,path+"U",ans,visited);//up
    Helper(matrix,row, column-1,path+"L",ans,visited);//left
    visited[row][column]=false;//unvisit
    
}
vector<string> FindPath(vector<vector<int>> matrix){
    int n =matrix.size();
    string path="";
    vector<string> ans;
    vector<vector<bool>> visited(n,vector<bool>(n,false));
    Helper(matrix,0,0,path,ans,visited);
    return ans;
}

*/