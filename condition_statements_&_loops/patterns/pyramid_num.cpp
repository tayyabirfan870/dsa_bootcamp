/* 
      1
    1 2 1
  1 2 3 2 1  
1 2 3 4 3 2 1
*/

#include<iostream>
using namespace std;
int main(){
    int n=4;
    for(int i=0; i<n; i++){
        for(int j=1; j<n-i; j++){
            cout<<"  ";
        }
        for(int k=1; k<=i+1; k++){
            cout<<k<<" ";
        }
        for(int l=i; l>0; l--){
            cout<<l<<" ";
        }
        cout<<"\n";
    }
    
    return 0;
}