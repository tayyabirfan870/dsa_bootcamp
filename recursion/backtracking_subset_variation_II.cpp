#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void GetAllsubSet(vector<int> &arr,vector<int> &current_subset, int i, vector<vector<int>> &allsubset){
    if(i==arr.size()){
        allsubset.push_back({current_subset});
        return;
    }
    current_subset.push_back(arr[i]);
    GetAllsubSet(arr,current_subset,i+1,allsubset);
    current_subset.pop_back();
    int index=i+1;
    while(index<arr.size() && arr[index]==arr[index-1]) index++;
    GetAllsubSet(arr,current_subset,index,allsubset);
}
vector<vector<int>> SubSet(vector<int> &arr){
    sort(arr.begin(),arr.end());
    vector<vector<int>> allsubset;
    vector<int> current_subset;
    GetAllsubSet(arr,current_subset,0,allsubset);
    return allsubset;

}
int main(){
    vector<int> arr={2,1,2};
        vector<vector<int>> print=SubSet(arr);
    for(int i=0; i<print.size(); i++){
        cout<<"{ ";
        for(int j=0; j<print[i].size(); j++){
            cout<<print[i][j]<<" ";
        }
        cout<<"}";
    }
    return 0;
}