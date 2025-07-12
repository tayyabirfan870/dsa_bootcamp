#include<iostream>
using namespace std;
int main(){
     int n=5;
     double ans=1;
    float x=4.5;
    if(n<0){
        x=1/x;
        n=-n;
    }
    while(n>0){
        if(n%2==1){
            ans*=x;
        }
            x*=x;
            n/=2;
    }
    cout<<"your ans= "<<ans<<endl;
    return 0;
}