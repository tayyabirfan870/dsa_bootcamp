#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
vector<int> FindMissingAndReatedValue(vector<vector<int>> grid){
    vector<int> ans;
    int n=grid.size();
    unordered_set<int> set;
    int a,b ,actualSum=0, extpectedSum=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            actualSum+=grid[i][j];
            if(set.find(grid[i][j])!= set.end()){
                a=grid[i][j];
                ans.push_back(a);
            }
                set.insert(grid[i][j]);
        }
    }
    extpectedSum=(n*n)*((n*n)+1)/2;
    b=extpectedSum+a-actualSum;
    ans.push_back(b);
    return ans;
}
int main(){
    vector<vector<int>> grid={{9,1,7},{8,9,2},{3,4,6}};
    vector<int> ans= FindMissingAndReatedValue(grid);
    cout<<"repeated val "<<ans[0]<<" missing val : "<<ans[1]<<endl; 
    return 0;
}