#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data=val;
        next=NULL;
    }
};
class Queue{
    Node* head;
    Node* rear;
    public:
    Queue(){
        head=rear=NULL;
    }
    bool empty(){
        return head==NULL;
    }
        void push(int val){
        Node* newNode=new Node(val);
        if(empty()){
            head=rear=newNode;
        }else{
            rear->next=newNode;
           rear=newNode;
        }
    }
    void pop(){
        if(empty()){
            cout<<"queue is empty "<<endl;
            return ;
    }
    Node* temp=head;
    head=head->next;
    temp->next=NULL;
    delete temp;
}
int front(){
    if(empty()){
        cout<<"queue is empty "<<endl;
        return -1;
    }
    return head->data;
}
};
int main(){
//    queue<int> q;
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