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
Node* helper(vector<int> &pre_order, int &i, int bound){
    if(i>= pre_order.size() || pre_order[i] > bound){
        return NULL;
    }
    Node* root = new Node(pre_order[i++]);
    root->left = helper(pre_order,i,root->data);
    root->right = helper(pre_order,i,bound);
    return root;
}
Node* ConstructBST(vector<int> &pre_order){
    int i=0;
    return helper(pre_order,i, INT16_MAX);
}
int main(){
    vector<int> pre_order={6,3,1,4,8,9};
    Node* root= ConstructBST(pre_order);
    cout<<root->left->right->data;
    return 0;
}