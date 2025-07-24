#include<iostream>
using namespace std;
void InsertionSort(int arr[],int n){
    for(int i=1; i<n; i++){
        int current=arr[i];
        int previous=i-1;
        while(previous>=0 && arr[previous]>current){
            arr[previous+1]=arr[previous];
            previous--;
        }
        arr[previous+1]=current;
    }
}
int main(){
    int n=5;
    int arr[]={23,1,10,5,2};
    InsertionSort(arr,n);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;


}