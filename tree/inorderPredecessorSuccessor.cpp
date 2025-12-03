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

Node* rightMostInLeftSubtree(Node* root){
    Node* ans;
    while(root != NULL){
        ans = root;
        root = root->right;
    }
    return ans;
}

Node* leftMostInRightSubtree(Node* root){
    Node* ans;
    while(root != NULL){
        ans = root;
        root = root->left;
    }
    return ans;
}

vector<int> getPredecessorSuccessor(Node* root, int key){
    Node* curr=root;
    Node* predecessor;
    Node* successor;

    while(curr != NULL){
        if(key < curr->data){
            successor=curr;
            curr=curr->left;
        }else if(key > curr->data){
            predecessor=curr;
            curr=curr->right;
        }else{
            if(curr->left != NULL){
               predecessor= rightMostInLeftSubtree(curr->left);
            }
            if(curr->right != NULL){
              successor =  leftMostInRightSubtree(curr->right);
            }
            break;
        }
    }
    return {predecessor->data, successor->data};
}

int main(){

    Node* root=new Node(6);
    root->left = new Node(4);
    root->right = new Node(8);
    root->left->left= new Node(1);
    root->left->right= new Node(5);
    root->right->left= new Node(7);
    root->right->right = new Node(9);

    int key=3;

    vector<int> ans = getPredecessorSuccessor(root,key);
    
    cout<<"predecessor:  "<<ans[0]<<endl;
    cout<<"successor: "<<ans[1]<<endl;


    return 0;
}