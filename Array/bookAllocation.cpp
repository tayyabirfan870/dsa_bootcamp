#include<iostream>
#include<vector>
using namespace std;
bool isValid(vector<int> pages, int n, int m, int maxAllocatePages){//O(n)
    int student=1; int allocatePages=0;
    for(int i=0; i<n; i++){
        if(pages[i]>maxAllocatePages){
            return false;
        }
        if(allocatePages+pages[i]<=maxAllocatePages){
            allocatePages+=pages[i];
        }else{
            student++;
            allocatePages=pages[i];
        }

    }
return student>m?false:true;

}
int allocateBook(vector<int> pages, int n, int m){//O(logn+n)
    if(m>n){return -1;}
   int sum=0;
       for(int i=0; i<n; i++){//O(n)
        sum+=pages[i];
    }
    int start=0; int end=sum; int ans=-1;
    while(start<=end){//O(logN)
        int mid=start+(end-start)/2;
        if(isValid(pages, n,m,mid)){
             ans=mid;
            end=mid-1;
        }else{
            start=mid+1;
        }
    }
    return ans;


}
int main(){
    vector<int> pages={15,17,20};
    int n=3, m=2;
   cout<<allocateBook(pages,n,m);

    return 0;
}