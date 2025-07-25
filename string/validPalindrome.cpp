#include<iostream>
using namespace std;
// bool isAlfaNum(char ch){
//     if((ch>='0' && ch<= '9' ) || (tolower(ch)>='a' && tolower(ch)<='z')){
//         return true;
//     }
//     return false;
// }
bool isValidPalindrome(string str){
    int start=0;
    int end=str.length()-1;
    while(start<end){
        if(! isalnum(str[start])){
            start ++; continue;
        }
        if(!isalnum(str[end])){
            end--; continue;
        }
        if(tolower(str[start]) != tolower(str[end])){
            return false;
        }
        start++; end--;
    }
    return true;
}

int main(){
    //string str="Ac3?e3c&a";
    string str="ra@#ce car";
    //string str="alpha";

    
   if(isValidPalindrome(str)){
    cout<<"yes string is valid palindrome "<<endl;
   }else{
    cout<<"string is not valid palindrome "<<endl;
   } 
   return 0;
}