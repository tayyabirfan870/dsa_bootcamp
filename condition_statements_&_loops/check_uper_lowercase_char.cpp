#include<iostream>
using namespace std;
int main(){
     char charector;
    cout<<"enter any upper or lower case char: ";
    cin>>charector;
    if(charector>=65 && charector<=90)//implicit type conversion thats way we can compare int and char
    {
        cout<<"u enter uppercase char ";
    }else if(charector>=97 && charector<=122)
    {
        cout<<"u enter lower case char:";
    }else{
        cout<<"u enter non alphabetic char :";
    }
    
    return 0;
}