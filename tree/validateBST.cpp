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
//for every Node we have value
//min=minimum allowed value
//max=maximum allowed value
bool helper(Node* root,Node* min,Node* max){
    if(root==NULL){
        return true;
    }
    if(min!=NULL && root->data<=min->data){
        return false;
    }
    if(max != NULL && root->data>=max->data){
        return false;
    }
    return helper(root->left,min,root) && helper(root->right,root,max);
}
bool isValidBST(Node* root){
    return helper(root,NULL,NULL);
}
int main(){
    vector<int> arr={3,2,1,5,6,4};
    Node* root=BuildBinarySearchTree(arr);
    InOrderTraversal(root);
    cout<<endl;
    if(isValidBST(root)){
        cout<<"BST is valid";
    }else{
        cout<<"BST is inValid";
    }
    return 0;
}