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
class CircularList{
    Node* head;
    Node* tail;
    public:
    CircularList(){
        head=tail=NULL;
    }
    void InsertAtHead(int val){
        Node* newNode=new Node(val);
        if(head==NULL){
            head=tail=newNode;
            // tail->next=newNode;
            tail->next=head;
        }else{

            newNode->next=head;
            // newNode->next=tail->next;
            head=newNode;
            // tail->next=newNode;
            tail->next=head;
        }
    }
    void InsertAtTail(int val){
        Node* newNode=new Node(val);
        if(tail==NULL){
            head=tail=newNode;
            newNode->next=head;
        }else{
            newNode->next=head;
            tail->next=newNode;
            tail=newNode;
        }
    }
    void deleteAtHead(){
        if(head==NULL){
            cout<<"CLL is empty "<<endl;
            return;
        }
        if(head==tail){
            delete head;
            head=tail=NULL;
            return;
        }
        Node* temp=head;
        head=head->next;
        tail->next=head;
        temp->next=NULL;
        delete temp;
    }
    void deleteAtTail(){
        if(head==NULL){
            cout<<"CLL is empty "<<endl;
            return;
        }else if(head==tail){
            delete head;
            head=tail=NULL;
        }else{
            Node* temp=tail;
            Node* prev=head;
            while(prev->next!=tail){
                 prev=prev->next;
            }
            tail=prev;
            tail->next=head;
            temp->next=NULL;
            delete temp;
        }
    }
    void print(){
        if(head==NULL) return;
         Node* temp=tail->next;
         do{
            cout<<temp->data<<" ";
            temp=temp->next;
         }while(temp!=tail->next);
         cout<<endl; 
    }

};
int main(){
    CircularList cll;
    cll.InsertAtHead(1);
    cll.InsertAtHead(0);
    cll.InsertAtTail(2);
    cll.deleteAtHead();
    cll.deleteAtTail();
    cll.deleteAtTail();
    cll.deleteAtTail();
    cll.print();
    return 0;
}