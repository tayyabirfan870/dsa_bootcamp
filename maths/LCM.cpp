#include<iostream>
using namespace std;
int gcdrec(int a ,int b){
    if(b==0){
        return a;}
        return gcdrec(b, a%b);
}
int lcm(int a, int b){
    return (a*b)/gcdrec(a,b);
}
int main(){
    int a=20, b=28;
    cout<<lcm(a,b);
    return 0;
}