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
Node* helper(vector<int> nums,int start,int end){
    if(start>end){
        return NULL;
    }
    int mid=start+(end-start)/2;
    Node* root=new Node(nums[mid]);

    root->left=helper(nums,start,mid-1);
    root->right=helper(nums,mid+1,end);

    return root;
}
Node* BuildBalanceBST(vector<int> nums){
    return helper(nums,0,nums.size()-1);
}
void InorderTravel(Node* root){
    if(root==NULL) return;
    InorderTravel(root->left);
    cout<<root->data<<" ";
    InorderTravel(root->right);
}
int main(){
    vector<int> nums={-10,-3,0,5,9};
    Node* root=BuildBalanceBST(nums);
    InorderTravel(root);
    return 0;
}