#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
vector<int> TwoSum(vector<int> arr, int target){
    unordered_map<int,int> map;
    vector<int> ans;
    for(int i=0; i<arr.size(); i++){
        int first=arr[i];
        int complement=target-first;
        if(map.find(complement) != map.end()){
            ans.push_back(i);
            ans.push_back(map[complement]);
            break;
        }
        map[first]=i;
    }
    return ans;
}
int main(){
    vector<int> arr={5,2,11,7,15};
    int target=9;
    vector<int> ans= TwoSum(arr,target);
    cout<<ans[0]<<","<<ans[1]<<endl;
    return 0;
}