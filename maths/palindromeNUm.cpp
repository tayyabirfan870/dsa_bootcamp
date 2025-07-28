#include<iostream>
using namespace std;
int reverseNum(int num){
    int revnum=0;
    while(num>0){
        int digit=num%10;
        if(revnum>INT32_MAX/10 || revnum<INT32_MIN/10){
            return 0;
        }
        revnum=(revnum*10)+digit;
        num/=10;
    }
    return revnum;
}
bool isPalindrome(int n){
    if(n<0){
        return false;
    }
    return n==reverseNum(n);
}
int main(){
    int num=0;
    if(isPalindrome(num)){
        cout<<"the number is palindrome "<<endl;
    }else{
        cout<<"the number is not palindrome "<<endl;
    }
    return 0;
}