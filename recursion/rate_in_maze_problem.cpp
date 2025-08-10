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

1. Problem Representation:
The maze is typically represented as a 2D array or matrix where cells marked '1' are open paths and '0' are blocked walls.
The rat starts at a designated source (e.g., top-left corner) and aims to reach a destination (e.g., bottom-right corner).
The rat can usually move in four directions: up, down, left, and right.
A key constraint often involves not revisiting already visited cells within a single path.
2. Recursion:
Recursion is used to explore potential paths from the current position.
A recursive function is defined that takes tohe current cordinates (row, column) as input.
Base Case: If the rat reaches the destination cell, a path has been found, and the function can record or print it.
Recursive Step: From the current cell, the function attempts to move in each valid direction (up, down, left, right).
For each valid move, it recursively calls itself with the new coordinates.
3. Backtracking:
Backtracking is the mechanism that allows exploration of alternative paths when a dead end is encountered or a path leads to a blocked cell.
Marking Visited Cells: Before making a recursive call to a new cell, that cell is typically marked as "visited" or "part of the current path" to prevent cycles and ensure each cell is visited only once per path.
Undoing Changes (Backtracking): If a recursive call from a particular cell does not lead to a solution (e.g., it hits a dead end or no valid moves are possible), the algorithm "backtracks." This involves:
Unmarking the current cell as "visited" or "part of the path." This effectively removes it from the current path and allows it to be considered for other potential paths.
Returning to the previous position in the recursion stack to explore other untried directions from that position.
*/




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