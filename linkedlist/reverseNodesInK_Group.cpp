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
Node* reverseKGroup(Node* head,int k){
    Node* temp=head;
    int count=0;
    //check if K nodes exist
    while(count<k){
        if(temp==NULL) return head;
        temp=temp->next;
        count++;
    }
    //recursively reverse rest of list
    Node* newNext=reverseKGroup(temp,k);
    //reverse current group
    temp=head;
    count=0;
    while(count<k){
        Node* nextptr=temp->next;
        temp->next=newNext;
        newNext=temp;
        temp=nextptr;
        count++;
    }
    head=newNext;
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
int main(){
    Node* head=new Node(1);
    Node* second=new Node(2);
    Node* third=new Node(3);
    Node* forth=new Node(4);
    Node* fifth=new Node(5);
    head->next=second;
    second->next=third;
    third->next=forth;
    forth->next=fifth;
    print(head);
    Node* newhead= reverseKGroup(head,3);
    print(newhead);
    return 0;
}