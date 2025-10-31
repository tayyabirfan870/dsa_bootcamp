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
Node* Prev=NULL;
int MinDiffInBST(Node* root){
    
    if(root==NULL){
        return INT16_MAX;
    }
    int ans=INT16_MAX;
    if(root->left !=NULL){
        int leftMin=MinDiffInBST(root->left);
        ans=min(ans,leftMin);
    }

    if(Prev != NULL){
        ans=min(ans,root->data-Prev->data);
    }
    Prev=root;
    if(root->right != NULL){
        int rightMin = MinDiffInBST(root->right);
        ans = min(ans,rightMin);
    }
    return ans;
}
int main(){
    vector<int> arr={83,62,88,42,82,52};
    Node* root=BuildBinarySearchTree(arr);
    cout<<MinDiffInBST(root);
    return 0;
}