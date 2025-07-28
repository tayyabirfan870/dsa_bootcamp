#include<iostream>
using namespace std;
int reverseNum(int num){
    int revnum=0;
    int digit;
    while(num!=0){
        digit=num%10;
        if(revnum>INT32_MAX/10 || revnum<INT32_MIN/10){
            return 0;
        }
        revnum=(revnum*10)+digit;
        num/=10; 
    }
    return revnum;
}
int main(){
    int num=123456789;
    cout<<reverseNum(num)<<endl;
    return 0;
}