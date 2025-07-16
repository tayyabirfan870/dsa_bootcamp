#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
// brute force O(n2)
int majorityElementBruteForce(vector<int> nums){
    int n=nums.size();
    for(int val: nums){
        int frequency=0;
        for(int element: nums){
            if(val==element){
                frequency++;
            }
        }
        if(frequency>(n/2)){
            return val;
        }
    }

}
// optimize approach O(nlogn)
int majorityElementOptimiz(vector<int> nums){
    sort(nums.begin(),nums.end());
    int n=nums.size();
    int ans=nums[0];
    int frequency=1;
    for(int i=1; i<n; i++){
        if(nums[i]==nums[i-1]){
            frequency++;
        }else{
            frequency=1;
            ans=nums[i];
        }
            if(frequency>(n/2)){
        return ans;
    }
    }
}

// mojority element by Moore's algo O(n)
int majorityElementByMooreAlgo(vector<int> nums){
    int ans=0;
    int frequency=0;
    for(int i=0; i<nums.size(); i++){
        if(frequency==0){
            ans=nums[i];
        }
        if(ans==nums[i]){
            frequency++;
        }else{
            frequency--;
        }
    }
    return ans;
}

int main(){
    vector<int> nums={2,2,2,1,1};
    cout<<"majority element by brute force approach : "<<majorityElementBruteForce(nums)<<endl;
    cout<<"majority element by optimized approach : "<<majorityElementOptimiz(nums)<<endl;
    cout<<"majority element by moore's algorithem : "<<majorityElementByMooreAlgo(nums)<<endl;
    return 0;
}