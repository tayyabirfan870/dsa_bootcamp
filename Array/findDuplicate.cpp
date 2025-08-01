#include<iostream>
#include<unordered_set>
using namespace std;
#include<vector>
int FindDuplicate(vector<int> nums){
    unordered_set<int> set;
    // for(int i=0; i<nums.size(); i++){
    //     if(set.find(nums[i]) != set.end()){
    //         return nums[i];
    //     }
    //     set.insert(nums[i]);
    // }
for(int val: nums){
            if(set.find(val) != set.end()){
            return val;
        }
        set.insert(val);

}
return -1;
}
int SlowFastApproach( vector<int> nums){
    int slow=nums[0],fast=nums[0];
    do{
        slow=nums[slow];//+1
        fast=nums[nums[fast]];//+2
    }while(slow != fast);
    slow=nums[0];
    while(slow!=fast){
        slow=nums[slow];//+1
        fast=nums[fast];//+1
    }
    return slow;
}
int main(){
    vector<int> nums={3,1,3,4,2};
    cout<<FindDuplicate(nums)<<endl;
    cout<<SlowFastApproach(nums)<<endl;
    return 0;
}