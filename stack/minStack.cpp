#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
// class MinStack{
// stack<pair<int,int>> s;
// public:
// void push(int val){
//     if(s.empty()){
//         s.push({val,val});
//     }else{
//         int minval=min(val,s.top().second);
//         s.push({val,minval});
//     }
// }
// void pop(){
//     s.pop();
// }
// int top(){
//     return s.top().first;
// }
// int getMin(){
//     return s.top().second;
// }
// bool isempty(){
//     return s.size()==0;
// }

// };

class MinStack{
    long long int minval;
    stack<long long int> s;
    public:
    int getMin(){
        return minval;
    }
    void push(int val){
        if(s.empty()){
            s.push(val);
            minval=val;
        }else if(val<minval){
            s.push((long long)2*val-minval);
            minval=val;
        }else{
            s.push(val);
        }
    }
    void pop(){
        if(s.top()<minval){
            minval=2*minval-s.top();
        }
        s.pop();
    }
    int top(){
        return s.top()<minval? minval:s.top(); 
    }
    bool isempty(){
        return s.size()==0;
    }
};
int main(){
    MinStack ms;
    ms.push(-2);
    ms.push(0);
    ms.push(-3);
        while(!ms.isempty()){
        cout<<"top "<<ms.top()<<" min "<<ms.getMin()<<endl;
        ms.pop();
    }
    return 0;
}