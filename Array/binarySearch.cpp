#include<iostream>
#include<vector>
using namespace std;
int binarySearchRecursive(vector<int> arr,int target, int start, int end){
    if(start<=end){
        int mid=start+(end-start)/2;
        if(target>arr[mid]){
           return binarySearchRecursive(arr,target,mid+1,end);
        }else if(target<arr[mid]){
            return binarySearchRecursive(arr,target,start,end-1);
        }else{
            return mid;
        }
    }
    return -1;
}


int binarySearchIterative(vector<int> arr, int target){
    int start=0;
    int end=arr.size()-1;
    while (start<=end){
        // int mid=(start+end)/2;
         int mid=start+(end-start)/2;//optimized approach
        if(target>arr[mid]){
            start=mid+1;
        }
        else if(target<arr[mid]){
            end=mid-1;
        }else{
            return mid;
        }

    }
    return -1;
    
}
int main(){
    vector<int> arrOdd={-1,0,3,4,5,9,12};//odd size
    int start=0;
    int end=arrOdd.size()-1;
    int target=12;
    cout<<"binary search by iterative approach "<<binarySearchIterative(arrOdd,target)<<endl;
    cout<<"binary search by recursive approach "<<binarySearchRecursive(arrOdd,target,start,end)<<endl;
    return 0;
}