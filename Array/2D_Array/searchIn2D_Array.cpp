#include<iostream>
#include<vector>
using namespace std;
int SearchTargetInRow(vector<vector<int>> matrix,int target, int row_index, int n){
    int start=0 ,end=n-1;
    while(start<=end){
        int column_index=start+(end-1)/2;
        if(matrix[row_index][column_index]==target){
            return column_index;
        }
         if(target>matrix[row_index][column_index]){
            start=column_index+1;
        }else{
            end=column_index-1;
        }
    }
    return -1;
}
pair<int,int> SearchTarget(vector<vector<int>> matrix,int target){
    int start=0; int end=matrix.size()-1;
    while(start<=end){
        int row_index=start+(end-start)/2;
       int n=matrix[row_index].size();
       if(target>=matrix[row_index][0] && target<=matrix[row_index][n-1]){
        int column_index =SearchTargetInRow(matrix,target,row_index,n);
        return {row_index,column_index};
       } 
        if(target>matrix[row_index][0]){
        start=row_index+1;
       }else{
        end=row_index-1;
       }
    }
    return {-1,-1};
}
int main(){
    vector<vector<int>> matrix={{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target=7;
    pair<int,int> cell = SearchTarget(matrix,target);
    cout<<cell.first<<","<<cell.second<<endl;
    return 0;
}