#include<iostream>
using namespace std;
class CircularQueue{
    int* arr;
    int front,rear;
    int current_size,capacity;
    public:
    CircularQueue(int cap){
        capacity=cap;
        arr=new int[capacity];
        front=0;
        rear=-1;
        current_size=0;
    }
    void push(int val){
        if(current_size==capacity){
            cout<<"capacity reached "<<endl;
            return;
        }
        rear=(rear+1)%capacity;
        arr[rear]=val;
        current_size++;
    }
    void pop(){
        if(empty()){
            cout<<"circular queue is empty "<<endl;
            return;
        }
        front=(front+1)%capacity;
        current_size--;
    }
    int Front(){
        if(empty()){
            cout<<"circular queue is empty "<<endl;
            return -1;
        }
        return arr[front];
    }
    bool empty(){
        return current_size==0;
    }
};
int main(){
    CircularQueue cq(3);
    cq.push(1);
    cq.push(2);
    cq.push(3);
    cq.pop();
    cq.push(4);
    while(!cq.empty()){
        cout<<cq.Front()<<" ";
        cq.pop();
    }
    return 0;
}