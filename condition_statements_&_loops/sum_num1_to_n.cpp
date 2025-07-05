#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter any number :";
    cin>>n;
    int sum=0;
    for(int i=0; i<=n; i++){
        sum+=i;
    }
    cout<<"sum from 0 to num "<<n<<" = "<<sum;
    return 0;
}