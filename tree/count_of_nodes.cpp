#include<iostream>
#include<vector>
#include<queue>
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
//height in term of Nodes
int Count(Node* root){
    if(root==NULL) return 0;
    int left_subtree_count=Count(root->left);
    int right_subtree_count=Count(root->right);
    return left_subtree_count+right_subtree_count+1;
}
int main(){
    vector<int> preorder_sequence={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root=BuildBinaryTree(preorder_sequence);
    cout<<Count(root);
    return 0;
}