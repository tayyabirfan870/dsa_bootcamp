#include<iostream>
using namespace std;
#include<vector>
bool IsPrime(int num){
    for(int i=2; i*i<=num; i++){
        if(num%i==0){
            return false;
        }
    }
    return true;
}
int CountPrimeNum(int n){
    vector<bool> isPrimeNum(n+1, true);
    int count=0;
    for(int i=2; i<n; i++){
        if(isPrimeNum[i]){
            count++;
                for(int j=i*i; j<n; j=j+i){
                isPrimeNum[j]=false;
            }
        }

    }
    return count;
}
int main(){
    int num=42;
    if(IsPrime(num)){
        cout<<"prime "<<endl;
    }else{
        cout<<"non prime "<<endl;
    }
    cout<<CountPrimeNum(42)<<endl;
    return 0;

}