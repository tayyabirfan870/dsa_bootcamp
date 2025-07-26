#include<iostream>
using namespace std;
#include<vector>
void compress(vector<char> &chArr ){
    int n=chArr.size();
    int index=0;
    for(int i=0; i<n; i++){
        int count=0;
        char ch=chArr[i];
        while(i<n && chArr[i]==ch){
            count++;  i++;
        }
        if(count==1){
            chArr[index++]=ch;
        }else{
            chArr[index++]=ch;
           string str= to_string(count); 
           for(char degit: str){
            chArr[index++]=degit;
           }
        }
        i--;
    }
    chArr.resize(index);
}
int main(){
    vector<char> chArr={'a','a','a','a','a','a','a','a','a','a','a','a','b','b','b','b','b','b','b','b','b','b','c'};
    compress(chArr);
    cout<<chArr.size()<<endl;
       for(char degit: chArr){
            cout<<degit<<" ";
           }
    return 0;
}