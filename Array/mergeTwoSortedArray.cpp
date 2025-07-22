#include<iostream>
#include<vector>
using namespace std;
void MergeTwoArrays(vector<int> &nums1, vector<int> &nums2,int m, int n){
    int i=m-1, j=n-1, k=m+n-1;
    while(j>=0){
        if(i>=0 && nums1[i]>nums2[j]){
            nums1[k]=nums1[i];
            i--;
        }else{
            nums1[k]=nums2[j];
            j--;
        }
        k--;
    }

}
int main(){
    vector<int> nums1={4,5,6,0,0,0};
    vector<int> nums2={3,5,9};
    int m=3;
    int n=3;
    MergeTwoArrays(nums1, nums2,m,n);
    for(int val: nums1){
        cout<<val<<" ";
    }
    return 0;
}