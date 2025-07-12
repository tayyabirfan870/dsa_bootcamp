#include<iostream>
#include<vector>
using namespace std;
int maxWaterByoptimizeapproach(vector<int>heights){
    int leftpointer=0;
    int rightpointer=heights.size()-1;
    int maxWater=0;
    while(leftpointer<rightpointer)
    {
        int width=rightpointer-leftpointer;
        int height=min(heights[leftpointer],heights[rightpointer]);
        int currentContainerWater=width*height;
        maxWater=max(maxWater,currentContainerWater);
        heights[leftpointer]<heights[rightpointer]?leftpointer++:rightpointer--;
    }
    return maxWater;
}
int main(){
vector<int>heights={1,8,6,2,5,4,8,3,7};
//by bruteforce approach
int maxWater=0;
for(int i=0; i<heights.size(); i++){
    for(int j=i+1; j<heights.size(); j++){
        int width=j-i;//container width
        int height=min(heights[j],heights[i]);//container height
        int waterInContainer=width*height; 
        maxWater=max(maxWater,waterInContainer);
    }
}
cout<<"Max water by bruteForce Approach = "<<maxWater<<endl;
cout<<"Max water by optimize approach = "<<maxWaterByoptimizeapproach(heights)<<endl;
    return 0;
}