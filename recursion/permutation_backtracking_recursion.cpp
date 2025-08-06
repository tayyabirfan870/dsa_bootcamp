#include<iostream>
#include<vector>
using namespace std;
void GetPermutation(vector<int> &arr, int current_position,  vector<vector<int>> &ans){
    if(current_position==arr.size()){
        ans.push_back({arr});
        return;
    }
    for(int i=current_position; i<arr.size(); i++ ){
        swap(arr[current_position], arr[i]);
        GetPermutation(arr,current_position+1,ans);
        swap(arr[current_position], arr[i]);
    }
}
vector<vector<int>> Permutation(vector<int> &arr){
    vector<vector<int>> ans;
    GetPermutation(arr,0,ans);
    return ans;
}
int main(){
    vector<int> arr={1,2,3};
    vector<vector<int>> print=Permutation(arr);
    for(int i=0; i<print.size(); i++){
        for(int j=0; j<print[i].size(); j++){
            cout<<print[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
