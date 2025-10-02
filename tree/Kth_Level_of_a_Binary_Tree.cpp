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
void KthLevel(Node* root,int k){
    if(root==NULL) return ;
    if(k==1){
        cout<<root->data<<" ";
        return;
    }
    KthLevel(root->left,k-1);
    KthLevel(root->right,k-1);
}
int main(){
    vector<int> preorder_sequence={1,2,7,-1,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root=BuildBinaryTree(preorder_sequence);
    KthLevel(root,3);
    return 0;
}