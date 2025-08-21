#include<iostream>
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
class List{
    Node* head;
    Node* tail;
    public:
    List(){
        head=tail=NULL;
    }
    void push_back(int val){
        Node* newNode =new Node(val);
        if(head==NULL){
            head=tail=newNode;
        }else{
            tail->next=newNode;
            tail=newNode;
        }
    }
    Node* getheadptr(){
        return head;
    } 
    Node* getTail(){
        return tail;
    }
};
Node* startingNode(Node* headptr){
    Node* slow=headptr;
    Node* fast=headptr;
    bool iscycle=false;
    while(fast !=NULL && fast->next !=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            iscycle=true;
            break;
        }
    }
    if(!iscycle){
        return NULL;
    }
    slow=headptr;
    Node* prev=NULL;
    while(slow!=fast){
        slow=slow->next;
        prev=fast;
        fast=fast->next;
    }
    prev->next=NULL;
    return slow;
}
bool HasCycle(Node* headptr){
    Node* slow=headptr;
    Node* fast=headptr;
    while(fast !=NULL && fast->next !=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) return true ;
    }
    return false;
}
int main(){
    List ll;
    ll.push_back(1);
    ll.push_back(2);
    Node* tailptr=ll.getTail();
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);
    Node* lastNodetail=ll.getTail();
    lastNodetail->next=tailptr; //cycle created
    Node* cyclicNode=startingNode(ll.getheadptr());
    cout<<cyclicNode->data<<endl;
    if(HasCycle(ll.getheadptr())){
        cout<<"linklist is cyclic "<<endl;
    }else{
        cout<<"cycle not find  "<<endl;
    }
    return 0;
}