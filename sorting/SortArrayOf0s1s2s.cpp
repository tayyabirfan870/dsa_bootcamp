#include<iostream>
#include<vector>
using namespace std;
void SortArrayBruteForce(vector<int> &arr){
    int n=arr.size();
    int count0=0 ,count1=0, count2=0;
    for(int i=0; i<n; i++){

        if(arr[i]==0){
            count0++;
        }else if(arr[i]==1){
            count1++;
        }else{
            count2++;
        }
    }
    int index=0;
    for(int i=0; i<count0; i++){
        arr[index]=0;
        index++;
    }
      for(int i=0; i<count1; i++){
        arr[index]=1;
        index++;
    }
      for(int i=0; i<count2; i++){
        arr[index]=2;
        index++;
    }
}
int main(){
    vector<int> arr={0,0,1,2,0,1,2,2,0,0};
    SortArrayBruteForce(arr);
    for(int val: arr){
        cout<<val<<" ";
    }

    return 0;
}