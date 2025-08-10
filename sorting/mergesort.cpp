#include<iostream>
#include<vector>
using namespace std;
void Merge(vector<int> &arr, int start, int mid, int end){
     vector<int> temp;
    int i=start,j=mid+1;
    while(i<=mid && j<=end){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i]);
            i++;
        }else{
            temp.push_back(arr[j]);
            j++;
        }
    }
    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=end){
        temp.push_back(arr[j]);
        j++;
    }
    for(int index=0; index<temp.size(); index++){
        arr[index+start]=temp[index];
    }
}
void MergeSort(vector<int> &arr, int start, int end){
    if(start<end){
        int mid=start+(end-start)/2;
        MergeSort(arr,start,mid);
        MergeSort(arr,mid+1,end);
        Merge(arr,start,mid,end);
    }
    
}
int main(){
    vector<int> arr={12,31,35,8,32,17};
    MergeSort(arr,0,arr.size()-1);
    for(int val : arr){
        cout<<val<<" ";
    }
    return 0;
}