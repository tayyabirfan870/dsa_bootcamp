#include<iostream>
#include<algorithm>
using namespace std;
#include<vector>
bool isPalindrome(string s){
    string s2=s;
    reverse(s2.begin(),s2.end());
    return s2==s;
}
void GetAllPalindromePart(string str, vector<string> partion, vector<vector<string>> &ans){
    if(str.size()==0){
        ans.push_back({partion});
        return;
    }
    for(int i=0; i<str.size(); i++ ){
        string part=str.substr(0,i+1);
        if(isPalindrome(part)){
            partion.push_back(part);
            GetAllPalindromePart(str.substr(i+1),partion,ans);
            partion.pop_back();
        }
    }
}
   vector<vector<string>> Partion(string str){
        vector<string> partion;
        vector<vector<string>> ans;
        GetAllPalindromePart(str,partion,ans);
        return ans;
    }
int main(){
    string str="aab";

    //cout<<str.substr(0+1);

        vector<vector<string>> print=Partion(str);
    for(int i=0; i<print.size(); i++){
        cout<<"{ ";
        for(int j=0; j<print[i].size(); j++){
            cout<<print[i][j]<<" ";
        }
        cout<<"}";
    }
return 0;
}