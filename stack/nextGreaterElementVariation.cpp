#include<iostream>
#include<stack>
#include<unordered_map>
#include<vector>
using namespace std;
vector<int> NextGreater(vector<int> arr1, vector<int> arr2){
    vector<int> ans(arr1.size(),0);
    stack<int> s;
    unordered_map<int, int> m;
    for(int i=arr2.size()-1; i>=0; i--){
        //removing invalid element 
        while(s.size()>0 && s.top()<=arr2[i]){
            s.pop();
        }
        m[arr2[i]]= s.empty()? -1:s.top();
        s.push(arr2[i]);
    }
    for(int i=0; i<arr1.size(); i++){
        ans[i]=m[arr1[i]];
    }
    return ans;
}
int main(){
    vector<int> arr1={4,1,2};
    vector<int> arr2={1,3,4,2};
    vector<int> ans=NextGreater(arr1,arr2);
    for(int val: ans){
        cout<<val<<" ";
    }
    return 0;
}
