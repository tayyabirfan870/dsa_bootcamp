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
Node* getInOrderSuccessor(Node* root){//left most node in right subtree
    while(root !=NULL && root->left!=NULL){
        root=root->left;
    }
    return root;
}
Node* DeleteNode(Node* root,int key){
    if(root==NULL){
        return NULL;
    }if(key<root->data){
        root->left=DeleteNode(root->left,key);
    }else if(key>root->data){
        root->right=DeleteNode(root->right,key);
    }else{
        //root==key
        if(root->left==NULL){
            Node* temp=root->right;
            delete root;
            return temp;
        }else if(root->right==NULL){
            Node* temp=root->left;
            delete root;
            return temp;
        }else{// 2 children
            Node* IS=getInOrderSuccessor(root->right);
            root->data=IS->data;
            root->right=DeleteNode(root->right,IS->data);
        }
    }
    return root;
}
int main(){
    vector<int> arr={3,2,1,7,8,5,6};
    Node* root=BuildBinarySearchTree(arr);
    cout<<"before :";
    InOrderTraversal(root);
    cout<<endl;

    DeleteNode(root,3);

    cout<<"after :";
    InOrderTraversal(root);
    
    return 0;
}