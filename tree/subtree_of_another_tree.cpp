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
Node* BuildBinaryTree(vector<int> preorder_sequence ,int &index){
    index++;
    if(preorder_sequence[index]==-1) return NULL;
    Node* root=new Node(preorder_sequence[index]);
    root->left=BuildBinaryTree(preorder_sequence,index);
    root->right=BuildBinaryTree(preorder_sequence,index);
    return root;
}
bool isIdenticalTree(Node* root1,Node* subroot){
    if(root1==NULL || subroot==NULL) return root1==subroot;
    bool leftSubTree=isIdenticalTree(root1->left,subroot->left);
    bool rightSubtree=isIdenticalTree(root1->right,subroot->right);
    return leftSubTree && rightSubtree && root1->data==subroot->data;
    //return root1->data==subroot->data && isIdenticalTree(root1->left,subroot->left) && isIdenticalTree(root1->right,subroot->right);
}

bool isSubtree(Node* root, Node* subroot){
    if(root==NULL || subroot==NULL) return root==subroot;
    if(root->data==subroot->data && isIdenticalTree(root,subroot)) return true;
    return isSubtree(root->left,subroot) || isSubtree(root->right,subroot);
}
int main(){
    vector<int> preorder_sequence1={1,2,-1,-1, 3,4,-1,-1,5,-1,-1};
    int index1=-1;
    Node* root1=BuildBinaryTree(preorder_sequence1,index1);
    vector<int> preorder_sequence2={3,4,-1,-1,5,-1,-1};
    int index=-1;
    Node* subroot=BuildBinaryTree(preorder_sequence2,index);
    cout<<isSubtree(root1,subroot);
    return 0;
}