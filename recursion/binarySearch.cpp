#include<iostream>
#include<vector>
using namespace std;
int BinarySearch(vector<int> nums, int target, int start,int end){
    if(start<=end){
        int mid=start+(end-start)/2;
        if(nums[mid]== target) return mid;
        if(nums[mid]<target){
             return BinarySearch(nums,target,mid+1, end);
        }else return BinarySearch(nums, target,start, mid-1);
    } 
    return -1;
}
int main(){
    vector<int> nums={1,3,4,6,7,8};
    int target=6;
    cout<<BinarySearch(nums,target,0,nums.size()-1);
    return 0;
}