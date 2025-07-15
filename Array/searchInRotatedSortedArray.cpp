#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> nums={6,7,0,1,2,3,4,5};
    int start=0;
    int end=nums.size()-1;
    int target=5;
    while (start<=end){
        int mid=start+(end-start)/2;
        if(target==nums[mid]){
            cout<<mid<<endl;
            return 0;
        }
        if(nums[start]<nums[mid]){
            if(nums[start]<=target && target<=nums[mid]){
                end=mid-1;
            }else{
                start=mid+1;
            }
        }else{
            if(nums[mid]<=target && target<=nums[end]){
                start=mid+1;
            }else{
                end=mid-1;
            }
        }
    }

}