#include<iostream>
using namespace std;
void SortArray(int arr[],int n){
    int mid=0,low=0,high=n-1;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[mid], arr[low]);
            low++;
            mid++;
        }else if(arr[mid]==1){
            mid++;
        }else{
            swap(arr[mid],arr[high]);
            high--;
        }
    }
}
int main(){
    int n=7;
    int arr[]={1,2,2,0,1,2,0};
    SortArray(arr,n);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;

}