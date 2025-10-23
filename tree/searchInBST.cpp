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
bool Search(Node* root,int key){
    if(root==NULL){
        return false;
    }
    if(root->data==key) return true;
    if(key<root->data){
        return Search(root->left,key);
    }else{
       return  Search(root->right,key);
    }
}
int main(){
    vector<int> arr={3,2,1,5,6,4};
    Node* root=BuildBinarySearchTree(arr);
    cout<<Search(root,0);
    return 0;
}