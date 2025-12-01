#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=right=NULL;
    }
};

Node* Prev=NULL;
Node* first=NULL;
Node* sec=NULL;
void InOrder(Node* root){
    if(root==NULL) return;
    InOrder(root->left);
    if(Prev != NULL && Prev->data > root->data ){
        if(!first){
            first=Prev;
        }
        sec=root;
    }
    Prev=root;
    InOrder(root->right);
}
void  RecoverBST(Node* root){
    InOrder(root);

    int temp;
    temp = first->data;
    first->data = sec->data;
    sec->data=temp;
    
}