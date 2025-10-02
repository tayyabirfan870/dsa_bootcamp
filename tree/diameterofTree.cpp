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
//height in term of Nodes
int ans=0;
int Height(Node* root){
    if(root==NULL) return 0;
    int left_subtree_Height=Height(root->left);
    int right_subtree_Height=Height(root->right);
    ans=max((left_subtree_Height+right_subtree_Height),ans);
    return max(left_subtree_Height,right_subtree_Height)+1;
}
int DiameterOfBinaryTree(Node* root){
    Height(root);
    return ans;
}
int main(){
    vector<int> preorder_sequence={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root=BuildBinaryTree(preorder_sequence);
    cout<<DiameterOfBinaryTree(root);
    return 0;
}
