#include<iostream>
using namespace std;
int Nfactorial(int n){
    if(n==0) return 1;

    return n*Nfactorial(n-1);
}
int main(){
    cout<<Nfactorial(5);
    return 0;
}