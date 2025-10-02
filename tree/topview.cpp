#include<iostream>
#include<vector>
#include<queue>
#include<map>
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
void TopView(Node* root){
    queue<pair<Node*,int>> q;
    map<int,int> m;
    
    q.push({root,0});
    while(q.size()>0){
        Node* curr =q.front().first;
        int currHD=q.front().second;
        q.pop();//pop k bd 2 chezain check krain gy 
        if(m.find(currHD)==m.end()){
            m[currHD]=curr->data;
        }
        if(curr->left!=NULL){
            q.push({curr->left,currHD-1});
        }
        if(curr->right!=NULL){
            q.push({curr->right,currHD+1});
        }
    }
    for(auto it: m){
        cout<<it.second<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int> preorder_sequence={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root=BuildBinaryTree(preorder_sequence);
    TopView(root);
    return 0;
}