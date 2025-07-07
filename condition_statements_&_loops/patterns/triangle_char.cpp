/*
A
B B
C C C
D D D D
*/
#include<iostream>
using namespace std;
int main(){
    int n=5;
    char ch='A';
    for(int i=0; i<n; i++){
        for(int j=0; j<i+1; j++){
            cout<<ch<<" ";
        }
        ch++;
        cout<<"\n";
    }
    return 0;
}