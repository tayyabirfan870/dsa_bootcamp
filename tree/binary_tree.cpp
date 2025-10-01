#include<iostream>
#include<vector>
#include<queue>
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
void preorder_traversal(Node* root){
    if(root==NULL) return ;
    cout<<root->data<<" ";
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}
void inorder_traversal(Node* root){
    if(root==NULL) return ;
    inorder_traversal(root->left);
    cout<<root->data<<" ";
    inorder_traversal(root->right);
}
void postorder_traversal(Node* root){
    if(root==NULL) return ;
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    cout<<root->data<<" ";
}
void levelorder_traversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(q.size()>0){
        Node* current_node=q.front();
        q.pop();
        if(current_node==NULL){
            if(!q.empty()){
                cout<<endl;
                q.push(NULL);
                continue;
            }else{
                break;
            }
        }
        cout<<current_node->data<<" ";
        if(current_node->left!=NULL) q.push(current_node->left);
        if(current_node->right!=NULL) q.push(current_node->right);
    }

}
int main(){
    vector<int> preorder_sequence={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root=BuildBinaryTree(preorder_sequence);
    preorder_traversal(root);
    cout<<endl;
    inorder_traversal(root);
    cout<<endl;
    postorder_traversal(root);
    cout<<endl;
    levelorder_traversal(root);
    return 0;
}