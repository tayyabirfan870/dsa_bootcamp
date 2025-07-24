#include<iostream>
#include<algorithm>
using namespace std;
void ReverseString(string &str){
    // int start=0;
    // int end=str.length()-1;
    // while(start<end){
    //     swap(str[start],str[end]);
    //     start++;end--;
    // }
     reverse(str.begin(),str.end());
}
void ReverseCharacterArray(char ch[],int n){
    int start =0;
    int end=n-1;
    while(start<end){
        swap(ch[start++],ch[end--]);    
    }
}
int main(){
    string str="tayyab";
    int n=6;
    char ch[]="tayyab";
    ReverseString(str);
    cout<<str<<endl;
    ReverseCharacterArray(ch,n);
    cout<<ch<<endl;
    return 0;
}