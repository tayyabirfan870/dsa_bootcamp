#include<iostream>
#include<vector>
#include<deque>
using namespace std;
vector<int> WindowMax(vector<int> arr,int k){
    deque<int> dq;
    vector<int> ans;
    //1st window
    for(int i=0; i<k; i++){
        while(dq.size()>0 && arr[dq.back()]<=arr[i]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    //other window 
    for(int i=k; i<arr.size(); i++){
        ans.push_back(arr[dq.front()]); 
        //remove elemet which are not part of current window
        while(dq.size()>0 && dq.front()<=i-k){
            dq.pop_front();
        }
        //remove the smaller val
        while(dq.size()>0 && arr[dq.back()]<=arr[i]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    ans.push_back(arr[dq.front()]);
    return ans;
}
int main(){
    vector<int> arr{1,3,-1,-3,5,3,6,7};
    int window_size=3;
    vector<int> ans=WindowMax(arr,window_size);
    for(int val: ans){
        cout<<val<<" ";
    }
    return 0;
}