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
Node* Insert(Node* root,int val){
    if(root==NULL){
        return new Node(val);
    }
    if(val<root->data){
        root->left=Insert(root->left,val);
    }else{
        root->right=Insert(root->right,val);
    }
    return root;
}
Node* BuildBinarySearchTree(vector<int> arr){
    Node* root=NULL;
    for(int val: arr){
        root=Insert(root,val);
    }
    return root;
}
void InOrderTraversal(Node* root){
    if(root==NULL) return;
    InOrderTraversal(root->left);
    cout<<root->data<<" ";
    InOrderTraversal(root->right);
}
Node* LCA(Node* root,Node* p,Node* q){
    if(root==NULL){
        return NULL;
    }
    if(root->data > p->data && root->data > q->data){
        return LCA(root->left,p,q);
    }else if(root->data < p->data && root->data < q->data){
        return LCA(root->right,p,q);
    }else{
        return root;
    }
}
int main(){
    vector<int> arr={6,2,0,4,3,5,8};
    Node* root=BuildBinarySearchTree(arr);
    Node* p=root->left->right->left;
    Node* q=root->left->right->right;
    Node* lowest_common_Ancestor=LCA(root,p,q);
    cout<<lowest_common_Ancestor->data;
    return 0;
}