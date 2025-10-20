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
 int index=-1;
Node* BuildBinaryTree(vector<int> preorder_sequence){
    index++;
    if(preorder_sequence[index]==-1) return NULL;
    Node* root=new Node(preorder_sequence[index]);
    root->left=BuildBinaryTree(preorder_sequence);
    root->right=BuildBinaryTree(preorder_sequence);
    return root;
}
vector<int> MorrisIorderTraversal(Node* root){
    vector<int> ans;
    Node* current=root;
    while(current!=NULL){
        if(current->left==NULL){
            ans.push_back(current->data);
            current=current->right;
        }else{
            Node* IP=current->left;
            while(IP->right!=NULL && IP->right!=current){
                IP=IP->right;
            }
            if(IP->right==NULL){
                IP->right=current;
                current=current->left;
            }else{//thread already exist meaning the left subtree has been traversal
                IP->right=NULL;
                ans.push_back(current->data);
                current=current->right;
            }
        }
    }
    return ans;
}
int main(){
    vector<int> preorder_sequence={1,2,-1,4,-1,-1,3,-1,-1};
    Node* root=BuildBinaryTree(preorder_sequence);
    vector<int> ans=MorrisIorderTraversal(root);
    for(int val: ans){
        cout<<val<<" ";
    }
    return 0;
}