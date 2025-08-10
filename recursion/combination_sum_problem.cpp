#include<iostream>
#include<vector>
#include<set>
using namespace std;
//set<vector<int>> s;
void CombinationSum(vector<int> arr,int i, vector<int> &combination,vector<vector<int>> &ans,int target){
    if(target <0 || i>=arr.size()){
        return;
    }
        if(target==0){
            // if(s.find({combination})==s.end()){
            //     ans.push_back({combination});
            //     s.insert({combination});
            // }
            ans.push_back({combination});
        return;
    }
    combination.push_back(arr[i]);
    //CombinationSum(arr,i+1,combination,ans,target-arr[i]);
    CombinationSum(arr,i,combination,ans,target-arr[i]);
    combination.pop_back();
    CombinationSum(arr,i+1,combination,ans,target);
}

int main(){
    vector<int> arr={2,3,5};
    vector<int> combination;
    vector<vector<int>> ans;
    int target=8;
    CombinationSum(arr,0,combination,ans,target);
    for(int i=0; i<ans.size(); i++){
        cout<<"{ ";
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"}";
    }
    return 0;
}