#include<iostream>
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

class Info{
    public:
    int min,max,size;
    Info(int mi,int mx,int sz){
        min=mi;
        max=mx;
        size=sz;
    }
};

Info helper(Node* root){
    if(root==NULL){
        return Info(INT16_MAX,INT16_MIN,0);
    }
    Info left=helper(root->left);
    Info right=helper(root->right);

    if(root->data > left.max && root->data < right.min){
        int currMin = min(root->data,left.min);
        int currMax = max(root->data,right.max);
        int currSize = left.size + right.size + 1;
        return Info(currMin, currMax,currSize);
    }

    return Info(INT16_MIN,INT16_MAX,max(left.size,right.size));
}

int LargestBSTinBT(Node* root){
    Info info=helper(root);
    return info.size;
}

int main(){
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(1);
    root->left->right= new Node(8);
    root->right->right = new Node(7);

    cout<<LargestBSTinBT(root);
    return 0;

}