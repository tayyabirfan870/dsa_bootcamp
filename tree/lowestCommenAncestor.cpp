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
Node* BuiltBinaryTree(vector<int> preorder,int &index){
    index++;
    if(preorder[index]==-1) return NULL;
    Node* root=new Node(preorder[index]);
    root->left=BuiltBinaryTree(preorder,index);
    root->right=BuiltBinaryTree(preorder,index);
    return root;
}
Node* findNode(Node* root,int val){
    if(root==NULL) return NULL;
    if(root->data==val) return root;
    Node* leftSearch=findNode(root->left,val);
    if(leftSearch!=NULL) return leftSearch;
    return findNode(root->right,val);
}
Node* LCA(Node* root,Node* p,Node* q){
    if(root==NULL) return NULL;
    if(root->data==p->data || root->data==q->data){
        return root;
    }
    Node* leftLCA=LCA(root->left,p,q);
    Node* rightLCA=LCA(root->right,p,q);
    if(leftLCA && rightLCA){
        return root;
    }else if(leftLCA!=NULL){// rightLCA is confirm that NULL
        return leftLCA;
    }else{
        return rightLCA;
    }
}
int main(){
    vector<int> preorder={1,2,4,-1,-1,5,8,-1,-1,9,-1,-1,3,6,-1,-1,7,-1,-1};
    int index=-1;
    Node* root=BuiltBinaryTree(preorder,index);
    Node* p=findNode(root,4);
    Node* q=findNode(root,9);
    Node* LCAval=LCA(root,p,q);
    cout<<LCAval->data;
    return 0;
}