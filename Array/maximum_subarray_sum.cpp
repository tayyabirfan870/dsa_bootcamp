#include<iostream>
using namespace std;
void print_subarray(int arr[],int sz){
     for(int st=0; st<sz; st++){
        for(int end=st; end<sz; end++){
            for(int i=st; i<=end; i++){
                cout<<arr[i];
            }
            cout<<" ";
        }
        cout<<"\n";}}
        // Maximum subarray sum function
        void MSS_bruteforce(int arr[], int sz){
            int max_sum=INT32_MIN;
            for(int st=0; st<sz; st++){
                int current_sum=0;
                for(int end=st; end<sz; end++){
                    current_sum+=arr[end];
                    max_sum=max(current_sum,max_sum);
                }

            }
             cout<<"maximum subarray sum  "<<max_sum<<"\n";
        }

        // kadane's algorithm 
        void MSS_kadane_algo(int arr[], int sz){
         int   max_sum=INT8_MIN;
         int current_sum=0;
         for(int i=0; i<sz; i++)
         {
            current_sum+=arr[i];
            max_sum=max(current_sum,max_sum);
            if(current_sum<0)
            {
                current_sum=0;
            }
         }

             cout<<"maximum subarray sum by optimised way "<<max_sum<<"\n";

        }


int main(){
    int size=5;
    int array[size]={5,4,-1,7,8};
    print_subarray(array, size);
    MSS_bruteforce(array, size);
    MSS_kadane_algo(array,size);
    return 0;
    // by tayyab irfan 
}