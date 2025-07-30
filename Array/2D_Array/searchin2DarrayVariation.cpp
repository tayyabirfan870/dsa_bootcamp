#include<iostream>
#include<vector>
using namespace std;
pair<int,int> SearchTarget(vector<vector<int>> matrix, int target){
    int n=matrix[0].size();
    int row=0, column=n-1;
    while(column>=0 &&  row<=n-1){
        if(target==matrix[row][column]){
            return {row,column};
        }
        if(target>matrix[row][column]){
            row++;
        }else{
            column--;
        }
    }
    return {-1,-1};

}
int main(){
    vector<vector<int>> matrix={{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22}};
    int target=0;
    pair<int,int> cell=SearchTarget(matrix,target);
    cout<<cell.first<<","<<cell.second<<endl;
    return 0;
}