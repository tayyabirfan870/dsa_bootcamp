#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int SubArraySumBruteForce(vector<int> nums ,int k){
    int n=nums.size();
    int count=0;
    for(int i=0; i<n; i++){
        int current_sum=0;
        for(int j=i; j<n; j++){
            current_sum+=nums[j];
            if(current_sum==k)  count++;

        }
    }
    return count;
}
int PrefixsumApproach(vector<int> nums ,int k){
    int n=nums.size();
    int count=0;
    vector<int> prefixSum(n,0);
    prefixSum[0]=nums[0];
    for(int i=1; i<n; i++){
        prefixSum[i]=prefixSum[i-1]+nums[i];
    }
    unordered_map<int,int> map;
    for(int j=0; j<n; j++){
        if(prefixSum[j]==k) count++;
        int val=prefixSum[j]-k;
        if(map.find(val) != map.end()){
            count +=map[val];
        }
        if(map.find(prefixSum[j])==map.end()){
            map[prefixSum[j]]=0;
        }
        map[prefixSum[j]]++;
    }
    return count;
}
int main(){
    vector<int> nums={9,4,0,20,3,10,5};
    int k =33;
    cout<<SubArraySumBruteForce(nums,k)<<endl;
    cout<<PrefixsumApproach(nums,k)<<endl;
    return 0;
}