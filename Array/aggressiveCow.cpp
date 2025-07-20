#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool isValid(vector<int> arr, int n, int c, int MinAllowedDist){
    int cows=1, lastStallpos=arr[0];
    for(int i=1; i<n; i++){
        if(arr[i]-lastStallpos>=MinAllowedDist){
            cows++;
            lastStallpos=arr[i];
        }
        if(cows==c){
            return true;
        }
    }
    return false;
}
int LargestMinimumDistance(vector<int> arr ,int n,int c){
    sort(arr.begin(), arr.end());
    int start=1 ,end=arr[n-1]-arr[0], ans=-1;
    while(start<=end){
      int  mid=start+(end-start)/2;
      if(isValid(arr,n,c,mid)){
        ans=mid;
        start=mid+1;
      }else{
        end=mid-1;
      }

    }
    return ans;
}
int main(){
    vector<int> arr={1,2,8,4,9};
    int n=5, c=3;
    cout<<LargestMinimumDistance(arr,n,c)<<endl;
    return 0;
}
