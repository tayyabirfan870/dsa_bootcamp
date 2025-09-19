#include<iostream>
#include<queue>
using namespace std;
class Stack{
    queue<int> main_queue;
    queue<int> helper_queue;
    public:
    void push(int data){
        while(!main_queue.empty()){
            helper_queue.push(main_queue.front());
            main_queue.pop();
        }

        main_queue.push(data);

        while(!helper_queue.empty()){
            main_queue.push(helper_queue.front());
            helper_queue.pop();
        }
    }
    int top(){
        if(main_queue.empty()){
            cout<<"stack is empty "<<endl;
            return -1;
        }
        return main_queue.front();
    }
    void pop(){
                if(main_queue.empty()){
            cout<<"stack is empty "<<endl;
            return ;
        }
        main_queue.pop();
    }
    bool empty(){
        return main_queue.empty();
    }
};
int main(){
    Stack s;
    cout<<s.top()<<endl;
    s.push(1);
    s.push(2);
    s.push(3);
    while (!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}