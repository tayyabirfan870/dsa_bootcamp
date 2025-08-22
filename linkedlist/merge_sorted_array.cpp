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
Node* Merge(Node* h1,Node* h2){
    if(h1==NULL || h2==NULL){
        return h1==NULL? h2:h1;
    }
    if(h1->data<=h2->data){
        h1->next=Merge(h1->next,h2);
        return h1;
    }else{
        h2->next=Merge(h1,h2->next);
        return h2;
    }
}
int main(){
    List ll;
    ll.push_back(1);
    ll.push_back(3);
    ll.push_back(5);
    List ll2;
    ll2.push_back(2);
    ll2.push_back(3);
    ll2.push_back(6);
    Node* headptr=Merge(ll.getheadptr(),ll2.getheadptr());
        Node* temp=headptr;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl; 

    return 0;
}