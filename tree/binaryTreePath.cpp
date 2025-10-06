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
void allPaths(Node* root,string path,vector<string> &ans){
    if(root->left==NULL && root->right==NULL){
        ans.push_back(path);
        return;
    }
    if(root->left){
        allPaths(root->left,path+"->"+to_string(root->left->data),ans);
    }
    if(root->right){
        allPaths(root->right,path+"->"+to_string(root->right->data),ans);
    }
}
vector<string> BinaryTreePaths(Node* root){
    vector<string> ans;
    string path=to_string(root->data);
    allPaths(root,path,ans);
    return ans;
}
int main(){
    vector<int> preorder_sequence={1,2,-1,5,-1,-1,3,-1,-1};
    Node* root=BuildBinaryTree(preorder_sequence);
    vector<string> ans=BinaryTreePaths(root);
    for(string path: ans){
        cout<<path<<endl;
    }
    return 0;
}