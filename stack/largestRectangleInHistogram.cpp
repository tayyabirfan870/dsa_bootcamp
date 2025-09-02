#include<iostream>
#include<stack>
#include<algorithm>
#include<vector>
using namespace std;
int LargestRectangleArea(vector<int> heights){
            stack<int> s;
    //right smaller 
        vector<int> right(heights.size(),0);
        for(int i=heights.size()-1; i>=0; i--){
            while(s.size()>0 && heights[s.top()]>=heights[i]){
                s.pop();
            }
            right[i]=s.empty() ? heights.size():s.top();
            s.push(i);
        }

        while(!s.empty()){
            s.pop();
        }
        //left smaller nearest
        vector<int> left(heights.size(),0);
        for(int i=0; i<heights.size(); i++){
            while(s.size()>0 && heights[s.top()]>=heights[i]){
                s.pop();
            }
            left[i]=s.empty() ? -1:s.top();
            s.push(i);
        }
        int ans=0;
        for(int i=0; i<heights.size(); i++){
            //int width=right[i]-left[i]-1;
            int currentArea=heights[i]*(right[i]-left[i]-1);
            ans=max(ans,currentArea);
        }
        return ans;
    }
int main(){
    vector<int> heights={2,1,5,6,2,3};
    cout<<"largest rectangle "<<LargestRectangleArea(heights);
    return 0;
}