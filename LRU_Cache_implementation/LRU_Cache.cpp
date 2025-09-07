#include<iostream>
#include<unordered_map>
using namespace std;
class Node{
    public:
    int data ,key;
    Node* next;
    Node* prev;
    Node(int k,int v){
        data=v;
        key=k;
        next=prev=NULL;
    }
};
class LRUCache{
Node* head=new Node(-1,-1);
Node* tail=new Node(-1,-1);
unordered_map<int,Node*> m;
int limit;
void AddNode(Node* newNode){
    Node* oldNext=head->next;

    head->next=newNode;
    oldNext->prev=newNode;

    newNode->next=oldNext;
    newNode->prev=head;
}
void delNode(Node* oldNode){
    Node* oldprev=oldNode->prev;
    Node* oldNext=oldNode->next;

    oldprev->next=oldNext;
    oldNext->prev=oldprev;
}
public:
LRUCache(int capacity){
    limit=capacity;
    head->next=tail;
    tail->prev=head;
}
void put(int key,int val){
        //if Node key already exit then overwrite
    if(m.find(key) != m.end()){
        Node* oldNode=m[key];
        delNode(oldNode);
        m.erase(key);
    }
    //if size reached
    if(m.size()==limit){
        // delete LRU data
        m.erase(tail->prev->key);
        delNode(tail->prev);
    }
    Node* newNode=new Node(key,val);
    AddNode(newNode);
    m[key]=newNode;
}
int get(int key){
    if(m.find(key)==m.end()){
        return -1;
    }
    Node* ansNode=m[key];
    int ans=ansNode->data;
    //make most recent data
    //delete node
    m.erase(key);
    delNode(ansNode);

    AddNode(ansNode);
    m[key]=ansNode;

    return ans;
}
};
int main(){
LRUCache* lRUCache = new LRUCache(2);
lRUCache->put(1, 11); // cache is {1=1}
lRUCache->put(2, 22); // cache is {1=1, 2=2}
cout<<lRUCache->get(1)<<endl;    // return 1
lRUCache->put(3, 33); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
cout<<lRUCache->get(2)<<endl;    // returns -1 (not found)
lRUCache->put(4, 44); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
cout<<lRUCache->get(1)<<endl;    // return -1 (not found)
cout<<lRUCache->get(3)<<endl;    // return 3
cout<<lRUCache->get(4)<<endl;    // return 4
    return 0;
}