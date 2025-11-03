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
int prev_order=0;
int KthSmallestInBST(Node* root,int k){
    if(root==NULL) return -1;
    //left 
    if(root->left != NULL){
        int left_ans=KthSmallestInBST(root->left,k);
        if(left_ans != -1){
            return left_ans;
        }
    }
    //root
    if(prev_order+1 ==k){
        return root->data;
    }
    prev_order+=1;
    //right
    if(root->right != NULL){
        int right_ans=KthSmallestInBST(root->right,k);
        if(right_ans != -1){
            return right_ans;
        }
    }
    return -1;
}
int main(){
    vector<int> arr={83,62,88,42,82,52};
    Node* root=BuildBinarySearchTree(arr);
    cout<<KthSmallestInBST(root,4);
    return 0;
}