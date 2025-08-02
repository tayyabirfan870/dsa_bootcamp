#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
vector<vector<int>> ThreeSum(vector<int> nums){
    int n=nums.size();
    vector<vector<int>> ans;
    set<vector<int>> set;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
             if(nums[i]+nums[j]+nums[k]==0){
                vector<int> triplet={nums[i],nums[j],nums[k]};
                sort(triplet.begin(),triplet.end());
                if(set.find(triplet)==set.end()){
                    set.insert(triplet);
                    ans.push_back(triplet);
                }
             }
            }
        }
    }
    return ans;
}
vector<vector<int>> ThreeSumBytwoSumHashing(vector<int> nums){
    int n=nums.size();
    set<vector<int>> uniquetriplets;
    for(int i=0; i<n; i++){
        int target=-nums[i];
        set<int> set;
        for(int j=i+1; j<n; j++){
            int third =target-nums[j];
            if(set.find(third) != set.end()){
                vector<int> trip={nums[i],nums[j], third};
                sort(trip.begin(), trip.end());
                uniquetriplets.insert(trip);
            }
            set.insert(nums[j]);
        }

    }
    return {uniquetriplets.begin(),uniquetriplets.end()};
}
vector<vector<int>> ThreeSumBYpointer( vector<int> nums){
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    int n=nums.size();
    for(int i=0; i<n; i++){
        if(i>0 && nums[i]==nums[i-1]){
            continue;
        }  
        int j=i+1, k=n-1;
        while(j<k){
           int current_sum =nums[i]+nums[j]+nums[k];
           if(current_sum<0){
            j++;
           }else if(current_sum>0){
            k--;
           }else{
            ans.push_back({nums[i],nums[j],nums[k]});
            j++; k--;
            while(j<k && nums[j]==nums[j-1]) j++;
           }
        }
    }
return ans;
}
int main(){
    vector<int> nums={-1,0,1,2,-1,-4};
   vector<vector<int>> ans= ThreeSum(nums);
   for(int i=0; i<ans.size(); i++){
    for(int j=0; j<ans[i].size(); j++){
        cout<<ans[i][j]<<" ";
    }
    cout<<endl;
   }
   vector<vector<int>> ans_optimize= ThreeSumBytwoSumHashing(nums);
   cout<<"ThreeSumBytwoSumHashing"<<endl;
      for(int i=0; i<ans_optimize.size(); i++){
    for(int j=0; j<ans_optimize[i].size(); j++){
        cout<<ans_optimize[i][j]<<" ";
    }
    cout<<endl;
   }
vector<vector<int>> ans_two_pointer= ThreeSumBYpointer(nums);
   cout<<"ThreeSumBYpointer"<<endl;
      for(int i=0; i<ans_two_pointer.size(); i++){
    for(int j=0; j<ans_two_pointer[i].size(); j++){
        cout<<ans_two_pointer[i][j]<<" ";
    }
    cout<<endl;
   }
    
    return 0;
}