#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
int Trap(vector<int> ht){
    int n=ht.size();
    vector<int> rightMax(n,0);
    vector<int> leftMax(n,0);
   leftMax[0]=ht[0];
    rightMax[n-1]=ht[n-1];
/*
The solution uses dynamic programming to pre-compute two arrays:
left[i]: stores the maximum height from the start up to position i
right[i]: stores the maximum height from position i to the end*/
    for(int i=1; i<n; i++){
        leftMax[i]=max(leftMax[i-1],ht[i]);
    }
        for(int i=n-2; i>=0; i--){
      rightMax[i]=max(rightMax[i+1],ht[i]);
    }
    /*
For each position, the water level above it is min(left[i], right[i]),
and the actual water trapped is min(left[i], right[i]) - height[i].
The total trapped water is the sum of water at all positions.
    */
    int ans=0;
    for(int i=1; i<n-1; i++){
        ans+=min(leftMax[i],rightMax[i])-ht[i];
    }
    return ans;
}

//space optimize
int WaterTrap(vector<int> ht){
    int n=ht.size();
    int ans=0;
    int leftMax=ht[0], rightMax=ht[n-1];
    int l=1, r=n-2;
    while(l<r){
       leftMax=max(leftMax,ht[l]);
       rightMax=max(rightMax,ht[r]);
        if(leftMax<rightMax){
            ans+=leftMax-ht[l];
            l++;
        }else{
            ans+=rightMax-ht[r];
            r--;
        }
    }
    return ans;
}
int main(){
    vector<int> heights={0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<Trap(heights)<<endl;
    cout<<WaterTrap(heights)<<endl;
    return 0;
}