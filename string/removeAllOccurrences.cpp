#include<iostream>
using namespace std;
void removeAllOccurrence(string &str,string part){
    while(str.find(part) != string::npos){
        str.erase(str.find(part), part.length());
    }
}
int main(){
    // string str="daabcbaabcbc";
    // string part="abc";
    string str="aa";
    string part="a";
    removeAllOccurrence(str,part);
    cout<<str;
    return 0;
}