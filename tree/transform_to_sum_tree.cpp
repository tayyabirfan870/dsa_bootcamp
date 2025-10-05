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
int TransformSum(Node* root){
    if(root==NULL) return 0;
    int leftSum=TransformSum(root->left);
    int rightSum=TransformSum(root->right);
    root->data+=leftSum+rightSum;
    return root->data;
}
int main(){
    vector<int> preorder_sequence={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root=BuildBinaryTree(preorder_sequence);
    cout<<TransformSum(root);
    return 0;
}