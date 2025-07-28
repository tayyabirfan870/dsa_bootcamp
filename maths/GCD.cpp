#include<iostream>
using namespace std;
int GCDByEuclidAlgo(int a, int b){
    while(a>0 && b>0){
        if(a>b){
            a%=b;
        }else{
            b%=a;
        }
    }
    if(a==0){
        return b;
    }
    return a;
}
int gcdrec(int a ,int b){
    if(b==0){
        return a;}
        return gcdrec(b, a%b);
}
int GCDbyBruteForce(int a, int b){
    int gcd=1;
    for(int i=1; i<=min(a,b); i++){
        if(a%i==0 && b%i==0){
            gcd=i;
        }
    }
    return gcd;
}
int main(){
    int a=20, b=28;
    cout<<GCDbyBruteForce(a,b)<<endl;
    cout<<GCDByEuclidAlgo(a,b)<<endl;
    cout<<gcdrec(a,b);
    return 0;
}