#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> _4Sum(vector<int> nums){
    int n=nums.size();
    vector<vector<int>> ans;
    for(int i=0; i<n; i++){
        if(i>0 && nums[i]==nums[i-1]) continue;
        for(int j=i+1; j<n;){
            int p=j+1, q=n-1;
            while(p<q){
                long long current_sum=(long long)nums[i]+(long long)nums[j]+(long long)nums[p]+(long long)nums[q];
                if(current_sum<0){
                    p++;
                }else if(current_sum>0){
                    q--;
                }else{
                    ans.push_back({nums[i],nums[j],nums[p],nums[q]});
                    p++; q--;
                    while(p<q && nums[p]==nums[p-1]) p++;
                }
            }
            j++;
            while(j<n && nums[j]==nums[j-1]) j++;
        }
    }
    return ans;
}
int main(){
    vector<int> nums={-2,-1,-1,1,1,2,2};
vector<vector<int>> ans= _4Sum(nums);
      for(int i=0; i<ans.size(); i++){
    for(int j=0; j<ans[i].size(); j++){
        cout<<ans[i][j]<<" ";
    }
    cout<<endl;
   }
   return 0;

}