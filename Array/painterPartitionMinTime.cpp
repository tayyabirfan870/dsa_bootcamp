#include<iostream>
#include<vector>
using namespace std;
bool isValid(vector<int> boards,int n, int m, int maxAllocateTime){
    int painter=1;
    int currentAllocateTime=0;
    for(int i=0; i<n; i++){
        if(currentAllocateTime+boards[i]<=maxAllocateTime){
            currentAllocateTime+=boards[i];
        }else{
            painter++;
            currentAllocateTime=boards[i];
        }
    }
    return painter<=m?true:false;

}
int MinTimeToPaint(vector<int> boards, int n, int m){
    int maxval=INT8_MIN, sum=0;
    for(int i=0; i<n; i++){
        sum+=boards[i];
        maxval=max(maxval,boards[i]);
    }
    int start=maxval,end=sum,ans=-1;
    while(start<=end){
       int mid=start+(end-start)/2;
       if(isValid(boards,n,m,mid)){
        ans=mid;
        end=mid-1;
       }else{
        start=mid+1;
       }

    }
    return ans;
}
int main(){
    vector<int> boards={40,30,10,20};
    int n=4,m=2;
    cout<<MinTimeToPaint(boards,n,m)<<endl;
    return 0;
}
