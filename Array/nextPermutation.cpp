#include<iostream>
#include<vector>
using namespace std;
void NextPermutation(int arr[], int n){
    int pivot=-1;
    for(int i=n-2; i>=0; i--){
        if(arr[i]<arr[i+1]){
            pivot=i;
            break;
        }
    }
    if(pivot==-1){
        int start=0;
        int end=n-1;
        while(start<end){
            swap(arr[start], arr[end]);
            start++; end--;
        }
        return;
    }

    for(int i=n-1; i>pivot; i--){
        if(arr[i]>arr[pivot]){
            swap(arr[i], arr[pivot]);
            break;
        }
    }
    int start=pivot+1;
    int end=n-1;
    while(start<end){
        swap(arr[start],arr[end]);
        start++; end--;
    }
}
int main(){
    int n=6;
  int arr[]={1,2,3,6,5,4};
    NextPermutation(arr,n);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" "; 
    }
    return 0;
}