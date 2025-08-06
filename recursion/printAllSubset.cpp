#include<iostream>
#include<vector>
using namespace std;
void PrintSubSet(vector<int> arr, vector<int> &ans, int i){
        if(i==arr.size()){
            cout<<"{ ";
        for(int val: ans){
            cout<<val<<" ";
        }
        cout<<"} ";
        return;
    }
    ans.push_back(arr[i]);
    PrintSubSet(arr,ans,i+1);
    ans.pop_back();
    PrintSubSet(arr,ans,i+1);
}
int main(){
    vector<int> arr={1,2,3};
    vector<int> ans;
    PrintSubSet(arr,ans,0);
return 0;
}