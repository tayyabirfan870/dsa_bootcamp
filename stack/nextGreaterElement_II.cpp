#include<iostream>
#include<stack>
#include<vector>
using namespace std;
vector<int> NextGreater(vector<int> nums){
    stack<int> s;
    int n=nums.size();
    vector<int> ans(n,0);
    for(int i=2*n-1; i>=0; i--){
        while(s.size()>0 && nums[s.top()]<=nums[i%n]){
            s.pop();
        }
        ans[i%n]=s.empty()?-1: nums[s.top()];
        s.push(i%n);
    }
    return ans;

}
int main(){
    vector<int> nums={3,6,5,4,2};
    vector<int> ans=NextGreater(nums);
    for(int val:ans){
        cout<<val<<" ";
    }
    return 0;
}