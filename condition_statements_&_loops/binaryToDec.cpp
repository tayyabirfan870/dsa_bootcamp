#include<iostream>
using namespace std;
int main(){
    int binaryNum=110010;
    int ans=0;
    int pow=1;
    while(binaryNum>0){
        int remainder=binaryNum%10;
        binaryNum=binaryNum/10;
        ans+=(remainder*pow);
        pow=pow*2;
    }
    cout<<"binary to decimal conversion : "<<ans<<endl;
    
    return 0;
}