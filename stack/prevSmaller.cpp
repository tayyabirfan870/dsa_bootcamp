#include<iostream>
#include<stack>
#include<vector>
using namespace std;
vector<int> PrevSmaller(vector<int> arr){
    stack<int> s;
    vector<int> ans(arr.size(),0);
    for(int i=0; i<arr.size(); i++){
        while(s.size()>0 && s.top()>=arr[i]){
            s.pop();
        }
        ans[i]=s.empty()? -1: s.top();
        s.push(arr[i]);
    }
    return ans;
}
int main(){
    vector<int> arr={3,1,0,8,6};
    vector<int> ans=PrevSmaller(arr);
    for(int val: ans){
        cout<<val<<" ";
    }
    return 0;
}