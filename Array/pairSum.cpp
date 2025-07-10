#include<iostream>
using namespace std;
#include<vector>
vector<int> pairSumBruteForce(vector<int> nums, int target){
    vector<int> ans;
    int n=nums.size();
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(nums[i]+nums[j]==target){
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
    return ans;
}
// optimize approach
vector<int> pairSumOptimize(vector<int> nums, int target){
    vector<int>ans;
    int n=nums.size();
    int i=0; int j=n-1;
    while(i<j){
        int pairsum=nums[i]+nums[j];
        if(pairsum>target){
            j--;
        }
        else if(pairsum<target){
            i++;
        }else{
            ans.push_back(i);
            ans.push_back(j);
            return ans;
        }
    }
}
int main(){
    vector<int> nums={2,7,11,15};
    int target=13;
    vector<int>ans=pairSumBruteForce(nums,target);
    cout<<"By bruteforce :"<<ans[0]<<" , "<<ans[1]<<endl;
    vector<int>ansOpt=pairSumOptimize(nums,target);
    cout<<"by optimized way: "<<ansOpt[0]<<" , "<<ansOpt[1]<<endl;
    return 0;

}