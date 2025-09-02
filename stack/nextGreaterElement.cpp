#include<iostream>
#include<stack>
#include<vector>
using namespace std;
vector<int> NextGreater(vector<int> arr){
    vector<int> ans(arr.size(),0);
    stack<int> s;
    for(int i=arr.size()-1; i>=0; i--){
        //removing invalid element 
        while(s.size()>0 && s.top()<=arr[i]){
            s.pop();
        }
        ans[i]= s.empty()? -1: s.top();
        s.push(arr[i]);
    }
    return ans;
}
int main(){
    vector<int> arr={6,8,0,1,3};
    vector<int> ans=NextGreater(arr);
    for(int val: ans){
        cout<<val<<" ";
    }
    return 0;
}
