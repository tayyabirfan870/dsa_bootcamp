#include<iostream>
#include<vector>
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
 int index=-1;
Node* BuildBinaryTree(vector<int> preorder_sequence){
    index++;
    if(preorder_sequence[index]==-1) return NULL;
    Node* root=new Node(preorder_sequence[index]);
    root->left=BuildBinaryTree(preorder_sequence);
    root->right=BuildBinaryTree(preorder_sequence);
    return root;
}
Node* next_right=NULL;
void FlattenBinaryTree(Node* root){
    if(root==NULL) return;
    FlattenBinaryTree(root->right);
    FlattenBinaryTree(root->left);
    root->left=NULL;
    root->right=next_right;
    next_right=root;
}

int main(){
    vector<int> preorder_sequence={1,2,3,-1,-1,4,-1,-1,5,-1,6,-1,-1};
    Node* root=BuildBinaryTree(preorder_sequence);
    FlattenBinaryTree(root);
    while(root !=NULL){
        cout<<root->data<<" ";
        root=root->right;
    }
    return 0;
}