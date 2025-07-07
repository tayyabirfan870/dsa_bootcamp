#include<iostream>
using namespace std;
int main(){
    int n=3;
    char ch='A';
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<ch<<" ";
            ch+=1;
        }
        cout<<"\n";
    } 
    cout<<ch<<"\n"; // J
    //int type_conversion=(int)ch;
    int type_conversion=ch;
    cout<<type_conversion; //74
    return 0;
}