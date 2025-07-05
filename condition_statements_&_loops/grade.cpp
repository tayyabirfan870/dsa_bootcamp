#include<iostream>
using namespace std;
int main(){
    int marks;
    cout<<"enter ur marks ";
    cin>>marks;
    if(marks>=90){
        cout<<"A+ grade\n";
    }else if(marks>=80 && marks<90){
        cout<<"B grade\n ";
    }else{
        cout<<"C grade :\n";
    }
    return 0;
}