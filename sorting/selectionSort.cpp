#include<iostream>
#include<vector>
using namespace std; 
void SelectionSort(vector<int> &arr){
    int n=arr.size();
    for(int i=0; i<n-1; i++){
        int smallestElementAtIndex=i;
        for(int j=i+1; j<n; j++){
            if(arr[j]<arr[smallestElementAtIndex]){
                smallestElementAtIndex=j;
            }
        }
        swap(arr[i],arr[smallestElementAtIndex]);
    }
}
int main(){
    vector<int> arr={5,4,2,1,6,3};
    SelectionSort(arr);
    for(int val: arr){
        cout<<val<<" ";
    }
    return 0;
}