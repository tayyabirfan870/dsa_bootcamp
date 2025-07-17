#include<iostream>
#include<vector>
using namespace std;
int SingleElement(vector<int> &nums){
    if(nums.size()==1){
        return nums[0];
    }
    int start=0;
    int end=nums.size()-1;
    while (start<=end)
    {
        int mid=start+(end-start)/2;
        if(mid==0 && nums[0]!=nums[1]){
            return nums[mid];
        }
        if(mid==nums.size()-1 && nums[nums.size()-1]!= nums[nums.size()-2]){
            return nums[mid];
        }
        if(nums[mid-1] != nums[mid] && nums[mid+1]!=nums[mid]){
            return nums[mid];
        }
        if(mid%2==0){
            if(nums[mid]==nums[mid-1]){
                end=mid-1;
            }else{
                start=mid+1;
            }
        }else{
            if(nums[mid]==nums[mid-1]){
                start=mid+1;

            }else{
                end=mid-1;
            }
        }
    }
    
}
int main(){
    vector<int> nums={1,1,2,2,3,3,4,4,5};
    cout<<SingleElement(nums)<<endl;
    return 0;
}