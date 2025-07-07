/*
1
2 3
4 5 6
7 8 9 10
*/
#include<iostream>
using namespace std;
int main(){
    int n=4;
    int num=1;
    for(int i=0; i<n; i++){
        for(int j=0; j<i+1; j++){
            cout<<num<<" ";
            num++;
        }
        cout<<"\n";
    }
    
    return 0;
}