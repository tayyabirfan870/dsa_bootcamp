#include<iostream>
using namespace std;
#include<vector>
int main(){
    vector<int>prices={7,1,5,3,6,4};
    int maxprofit=0;
    int bestbuy=prices[0];
    for(int i=1; i<prices.size(); i++){
        if(prices[i]>bestbuy){
            maxprofit=max(maxprofit,prices[i]-bestbuy);
        }
        bestbuy=min(bestbuy,prices[i]);
    }
    cout<<"max profit = "<<maxprofit<<"\n";
    return 0;
}