#include<iostream>
using namespace std;
int Fib(int n){
    if(n==0 || n==1){
        return n;
    }
    return Fib(n-1)+Fib(n-2);
}
int main(){
    cout<<Fib(6);
    return 0;
}