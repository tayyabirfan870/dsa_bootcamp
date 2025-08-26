#include<iostream>
#include<list>
using namespace std;
class Stack{
    list<int> ll;

    public:
    void push(int val){
        ll.push_front(val);
    }
    void pop(){
        ll.pop_front();
    }
    int top(){
        return ll.front();
    }
    bool isempty(){
        return ll.size()==0;
    }
};
int main(){
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    while(!s.isempty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}