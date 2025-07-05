#include<iostream>
using namespace std;
int main(){
    int n=17;
    bool isprime=true;
    //for(int i=2; i<=n-1;i++)
    for(int i=2; i*i<=n;i++){
        if(n%i==0){
            isprime=false;
            break;
        }
    }
    if(isprime==true){
        cout<<"the num is prime :\n";
    }else{
        cout<<"the num is non prime ";
    }
    return 0;
}