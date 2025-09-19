#include<iostream>
#include<stack>
using namespace std;
class Queue{
    stack<int> main_stack;
    stack<int> helper_stack;
    public:
    void push(int data){
        while(!main_stack.empty()){
            helper_stack.push(main_stack.top());
            main_stack.pop();
        }
        main_stack.push(data);
        while(!helper_stack.empty()){
            main_stack.push(helper_stack.top());
            helper_stack.pop();
        }
    }
    void pop(){
        if(main_stack.empty()){
            cout<<"queue is empty "<<endl;
            return;
        }
        main_stack.pop();
    }
    int front(){
                if(main_stack.empty()){
            cout<<"queue is empty "<<endl;
            return -1;
        }
        return main_stack.top();
    }
    bool empty(){
        return main_stack.empty();
    }
};
int main(){
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}