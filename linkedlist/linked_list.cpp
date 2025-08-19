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
    void push_front(int val){
        Node* newNode= new Node(val);
        //Node newNode(val); static 
            if(head==NULL){
        head=tail=newNode;
    }else{
        newNode->next=head;
        head=newNode;
    }
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
    void pop_front(){
        if(head==NULL){
            cout<<"linked list  is empty "<<endl;
            return;
        }
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    void pop_back(){
        if(head==NULL){
            cout<<"linked list is empty ";
            return;
        }
        Node* temp=head;
        while(temp->next !=tail){
            temp=temp->next;
        }
        temp->next=NULL;
        delete tail;
        tail=temp;
    }
    void insert(int val, int pos){
        if(pos<0){
            cout<<"invalid position"<<endl;
            return;
        }
        if(pos==0){
            push_front(val);
            return;
        }
        Node* newNode=new Node(val);
        Node* temp=head;
        for(int i=0; i<pos-1; i++){
            if(temp==NULL){
                cout<<"invalid position "<<endl;
                return;
            }
            temp=temp->next;
        }
        newNode->next=temp->next;
        temp->next=newNode;
    }
    int search(int key){
        Node* temp=head;
        int index=0;
        while(temp!=NULL){
            if(temp->data==key){
                return index;
            }
            temp=temp->next;
            index++;
        }
        return -1;
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
int main(){
    List ll;
    ll.push_back(1);
    ll.push_back(3);
    ll.push_back(4);
    ll.insert(0,0);
    cout<<ll.search(-7)<<endl;
    ll.print();
    return 0;
}