#include<iostream>
#include<vector>
using namespace std;
void GetAllSubSet(vector<int> arr, vector<int> &subset, int i, vector<vector<int>> &allsubset){
        if(i==arr.size()){
            allsubset.push_back({subset});
        return;
    }
    subset.push_back(arr[i]);
    GetAllSubSet(arr,subset,i+1,allsubset);
    subset.pop_back();
    GetAllSubSet(arr,subset,i+1,allsubset);
}
vector<vector<int>> SubSet(vector<int> arr){
        vector<int> subset;
    vector<vector<int>> allsubset;
    GetAllSubSet(arr,subset,0,allsubset);
    return allsubset;
}

int main(){
    vector<int> arr={1,2,3};
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