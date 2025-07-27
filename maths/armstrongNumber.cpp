#include<iostream>
using namespace std;
bool isArmstrong(int number){
    int numberCopy=number;
    int sumOfCubes=0;
    while(number!=0){
        int digit =number%10;
         sumOfCubes+=(digit*digit*digit);
         number/=10;
    }
    // if(numberCopy==sumOfCubes){
    //     return true;
    // }

return numberCopy==sumOfCubes;
}
int main(){
    int number =153;
    if(isArmstrong(number)){
        cout<<"the number is armstrong number "<<endl;
    }else{
        cout<<"not armstrong number "<<endl;
    }
    return 0;
}