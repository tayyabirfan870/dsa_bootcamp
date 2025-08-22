#include<iostream>
#include<unordered_map>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* random;
    Node(int val){
        data=val;
        next=NULL; 
        random=NULL;
    }
};
void print(Node* headptr){
    Node* temp=headptr;
    while(temp!=NULL){
        if(temp->random !=NULL){
            cout<<temp->random->data<<" ";
            
        }
        temp=temp->next;
    }
    cout<<endl;
}
Node* copyLinkedList(Node* head){
    Node* newHead=new Node(head->data);
    Node* oldtemp=head->next;
    Node* newtemp=newHead;
    unordered_map<Node*,Node*> m;
    m[head]=newHead;
    while(oldtemp!=NULL){
        Node* copyNode=new Node(oldtemp->data);
        m[oldtemp]=copyNode;
        newtemp->next=copyNode;
        oldtemp=oldtemp->next;
        newtemp=newtemp->next;
    }
    oldtemp=head;
    newtemp=newHead;
    while(oldtemp!=NULL){
        newtemp->random=m[oldtemp->random];
        oldtemp=oldtemp->next;
        newtemp=newtemp->next;
    }
    return newHead;
}
int main(){
    Node* head=new Node(7);
    Node* second=new Node(13);
    Node* third=new Node(11);
    Node* forth=new Node(10);
    Node* fifth=new Node(1);
    head->next=second;
    second->next=third;
    second->random=head;
    third->next=forth;
    third->random=fifth;
    forth->next=fifth;
    forth->random=third;
    fifth->random=head;
    print(head);
    Node* newhead=copyLinkedList(head);
    print(newhead);
    return 0;
}