#include<iostream>
using namespace std;
int main(){
    int decNum=42;
    int ans=0;
    int pow=1;
    while(decNum>0){
        int remainder=decNum%2;
        decNum=decNum/2;
        ans+=(remainder*pow);
        pow=pow*10;
    }
    cout<<"decimal number to binary : "<<ans<<endl;
    return 0;
}