#include<iostream>
#include<stack>
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

class BSTIterator{

stack<Node*> Stack;
void StoreLeftNodes(Node* root){
    while(root != NULL){
        Stack.push(root);
        root = root->left;
    }
}    
    public:

BSTIterator(Node* root){
    StoreLeftNodes(root);
}

int next(){
    Node* ans=Stack.top();
    Stack.pop();
    if(ans->right){
        StoreLeftNodes(ans->right);
    }
    return ans->data;
}

bool hasNext(){
    Stack.size() > 0;

}

};
int main(){
    return 0;
}