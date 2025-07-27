#include<iostream>
#include<math.h>
using namespace std;
void DigitsInNum(int number){
while(number>0){
        int digit =number%10;
    cout<<digit<<" ";
    number/=10;

}
}
int main(){
    int number=12345;
    DigitsInNum(number);
    cout<<"\n";
    cout<<(int)(log10(number)+1)<<endl;//count
    return 0;
}