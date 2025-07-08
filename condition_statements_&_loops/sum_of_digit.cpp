#include<iostream>
using namespace std;
int main(){
    int sumDigit=0;
    int num=14500008;
    while (num>0)
    {
       int lastDigit= num%10;
       sumDigit+=lastDigit;
       num=num/10;
    }
    cout<<"sum of the number : "<<sumDigit<<"\n";
    cout<<num;
    return 0;
}