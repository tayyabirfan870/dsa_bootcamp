#include<iostream>
#include<stack>
using namespace std;
bool isvalid(string str){
    stack<char> st;
    for(int i=0; i<str.size(); i++){//opening 
        if(str[i]=='(' || str[i]=='{' || str[i]=='['){
            st.push(str[i]);
        }else{//closing
            if(st.size()==0){
                return false;
            }
            if(st.top()=='(' && str[i]==')' || 
                st.top()=='{' && str[i]=='}'||
                st.top()=='[' && str[i]==']' ){
                    st.pop();
                }else{//no match
                    return false;
                }
        }
    }
    return st.size()==0;
}
int main(){
    string s1="({})";
    string s2="({}]";
    string s3="()}";
    string s4="({}";
    cout<<isvalid(s1)<<endl;
    cout<<isvalid(s2)<<endl;
    cout<<isvalid(s3)<<endl;
    cout<<isvalid(s4)<<endl;
    return 0;
}
