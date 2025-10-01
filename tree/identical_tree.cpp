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
bool isIdenticalTree(Node* root1,Node* root2){
    if(root1==NULL || root2==NULL) return root1==root2;
    bool leftSubTree=isIdenticalTree(root1->left,root2->left);
    bool rightSubtree=isIdenticalTree(root1->right,root2->right);
    return leftSubTree && rightSubtree && root1->data==root2->data;
}
int main(){
    vector<int> preorder_sequence={1, 2, -1, -1, 3, -1, -1};
    int index1=-1;
    Node* root1=BuildBinaryTree(preorder_sequence,index1);
    int index=-1;
    Node* root2=BuildBinaryTree(preorder_sequence,index);
    cout<<isIdenticalTree(root1,root2);
    return 0;
}