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
int Search(vector<int> inorder,int Left,int Right,int val){
    for(int i=Left; i<=Right; i++){
        if(inorder[i]==val){
            return i;
        }
    }
    return -1;
}
Node* BuildTree(vector<int> preorder,vector<int> inorder,int &preidx,int Left,int Right){
    if(Left>Right) return NULL;
    Node* root=new Node(preorder[preidx]);
    int inIdx=Search(inorder,Left,Right,preorder[preidx]);
    preidx++;
    root->left=BuildTree(preorder,inorder,preidx,Left,inIdx-1);
    root->right=BuildTree(preorder,inorder,preidx,inIdx+1,Right);
    return root;
}
int main(){
    vector<int> preorder={3,9,20,15,7};
    vector<int> inorder={9,3,15,20,7};
    int preidx=0;
    Node* root=BuildTree(preorder,inorder,preidx,0,preorder.size());
    cout<<root->right->left->data;
    return 0;
}