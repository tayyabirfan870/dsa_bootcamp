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
int MaxWidth(Node* root){
    queue<pair<Node* ,unsigned long long  int>> q;
    q.push({root,0});
    int max_Width=0;
    while(q.size()>0){
        int currentLevelSize=q.size();
       unsigned long long int stIdx=q.front().second;
        unsigned long long  int endIdx=q.back().second;
        max_Width=max(max_Width,(int)(endIdx-stIdx+1));
        for(int i=0; i<currentLevelSize; i++){
            pair<Node*,int> currentNode=q.front();
            q.pop();
            if(currentNode.first->left){
                q.push({currentNode.first->left,currentNode.second*2+1});
            }
            if(currentNode.first->right){
                q.push({currentNode.first->right,currentNode.second*2+2});
            }
            
        }
    }
    return max_Width;
}
int main(){
    vector<int> preorder_sequence={1,3,5,-1,-1,3,-1,-1,2,-1,9,-1,-1};
    Node* root=BuildBinaryTree(preorder_sequence);
    cout<<MaxWidth(root);

    return 0;
}