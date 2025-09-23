#include<iostream>
#include<vector>
using namespace std;
int CanCompleteCircle(vector<int> gas,vector<int> cost){
    int totalgas=0;
    int totalcost=0;
    // for(int val: gas){
    //     totalgas+=val;
    // }
    // for(int val: cost){
    //     totalcost+=val;
    // }
    // if(totalgas<totalcost) return -1;
    //unique solution always exist
    int start=0, current_tank_level=0;
    for(int i=0; i<gas.size(); i++){
        totalcost+=cost[i];
        totalgas+=gas[i];
        current_tank_level+=(gas[i]-cost[i]);
        if(current_tank_level<0){
            start=i+1;
            current_tank_level=0;
        }
    }
    return totalgas<totalcost? -1:start;
//    return start;
}
int main(){
    vector<int> gas={1,2,4,5,9};
    vector<int> cost={3,4,1,10,1};
    cout<<CanCompleteCircle(gas,cost);
    return 0;
}