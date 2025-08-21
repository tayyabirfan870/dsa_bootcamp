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
    void print(Node * headptr){
        Node* temp=headptr;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};
Node* reverseLinkedlist(Node* head){
    Node* current=head;
    Node* prev=NULL;
    Node* next=NULL;
    while(current !=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    return prev;
}
int main(){
    List ll;
    ll.push_back(1);
    ll.push_back(3);
    ll.push_back(4);
    ll.print(ll.getheadptr());
    Node* newHead=reverseLinkedlist(ll.getheadptr());
    ll.print(newHead);
    return 0;
}