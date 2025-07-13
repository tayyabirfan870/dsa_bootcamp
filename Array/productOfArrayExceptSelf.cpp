#include<iostream>
#include<vector>
using namespace std;
vector<int> productArrayBrute(vector<int> nums){
    vector<int>ans(nums.size(),1);
    for(int i=0; i<nums.size(); i++){
        //int product=1;
        for(int j=0; j<nums.size(); j++){
            if(i!=j){
                //product*=nums[j];
                ans[i]*=nums[j];
            }
        }
        //ans[i]=product;

    }
    return ans;
}
vector<int> productArrayOptimize(vector<int> nums){
    vector<int>ans(nums.size(),1);
    vector<int>prefix(nums.size(),1);
    vector<int>suffix(nums.size(),1);
    for(int i=1; i<nums.size(); i++){
        prefix[i]=prefix[i-1]*nums[i-1];
    }
    for(int i=nums.size()-2; i>=0; i--){
        suffix[i]=suffix[i+1]*nums[i+1];
    }
    for(int i=0; i<nums.size(); i++){
        ans[i]=prefix[i]*suffix[i];
    }
    return ans;
}
vector<int> productArrayOptSpace(vector<int> nums){
    vector<int>ans(nums.size(),1);
    for(int i=1; i<nums.size(); i++){
        ans[i]=ans[i-1]*nums[i-1];
    }
    int suffix=1;
    for(int i=nums.size()-2; i>=0; i--){
        suffix*=nums[i+1];
        ans[i]*=suffix;
    }
    return ans;
}
int main(){
    vector<int>nums={1,2,3,4};
    vector<int>ansBrute=productArrayBrute(nums);
    cout<<"product of array by brute force : ";
    for(int val:ansBrute){
        cout<<val<<" ";
    }
    cout<<'\n';
    vector<int>ansOptimize=productArrayOptimize(nums);
        cout<<"product of array by optimze time complexity o(n) : ";
    for(int val:ansOptimize){
        cout<<val<<" ";
    }
    cout<<'\n';
        vector<int>ansOptimizeSpace=productArrayOptSpace(nums);
        cout<<"product of array by optimze  space complexity  : ";
    for(int val:ansOptimizeSpace){
        cout<<val<<" ";
    }
    cout<<'\n';

}
