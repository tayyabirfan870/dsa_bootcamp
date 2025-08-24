#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node* child;
    Node(int val){
        data=val;
        next=prev=child=NULL;
    }
};
class Doublylist{
    Node* head;
    Node* tail;
    public:
    Doublylist(){
        head=tail=NULL;
    }
    void push_back(int val){
        Node* newNode=new Node(val);
        if(head==NULL){
            head=tail=newNode;
        }else{
            newNode->prev=tail;
            tail->next=newNode;
            tail=newNode;
        }
    }
    Node* getTail(){
        return tail;
    }
    Node* getHead(){
        return head;
    }
        void print(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};

Node* FlattenList(Node* headptr){
    if(headptr==NULL) return headptr;
    Node* current=headptr;
    while(current!=NULL){
        //flatten list
        if(current->child!=NULL){
            Node* nextptr=current->next;
            current->next= FlattenList(current->child);
            current->next->prev=current;
            current->child=NULL;
            //find tail
            while(current->next!=NULL){
                current=current->next;
            }
            //attach with nextptr
            if(nextptr!=NULL){
            current->next=nextptr;
            nextptr->prev=current;
            }
        }
        current=current->next;
    }
    return headptr;
}
int main(){
    Doublylist dll;
    Doublylist dll2;
    dll.push_back(0);
    dll.push_back(1);
    Node* tailptr =dll.getTail();
    dll.push_back(2);
    dll.push_back(3);
    dll2.push_back(4);
    dll2.push_back(5);
    dll2.push_back(6);
    tailptr->child=dll2.getHead();
    dll.print();
    FlattenList(dll.getHead());
    dll.print();
    return 0;
}