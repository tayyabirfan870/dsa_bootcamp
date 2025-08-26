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
    void print(Node * headptr){
        Node* temp=headptr;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

    Node* Swap(Node* head){
        if(head==NULL || head->next==NULL) return head;
        Node* first=head;
        Node* second=head->next;
        Node* prev=NULL;
        while(first!= NULL && second!=NULL){
            Node* third=second->next;
            second->next=first;
            first->next=third;
            if(prev!=NULL){
                prev->next=second;
            }else{
                head=second;
            }
            //updation
            prev=first;
            first=third;
            if(third!=NULL){
                second=third->next;
            }else{
                second=NULL;
            }
        }
        return head;   
    }
int main(){
    Node* head= new Node(1);
    Node* second= new Node(2);
    Node* third= new Node(3);
    Node* forth= new Node(4);
    head->next=second;
    second->next=third;
    third->next=forth;
    print(head);
    Node* newhead=Swap(head);
    print(newhead);
    return 0;
}