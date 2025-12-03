#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node* next;
    Node(int val){
        data=val;
        left=right=next=NULL;
    }
};
Node* connect(Node* root){
    if(root ==NULL || root->left== NULL){
        return root;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL); //mark the end of a level

    Node* Prev = NULL;

    while(q.size() > 0){
        Node* curr = q.front();
        q.pop();
        if(curr == NULL){
            if(q.size() == 0){
                break;
            }
            q.push(NULL);
        }else{
            if(curr->left != NULL){
                q.push(curr->left);
            }
            if(curr->right != NULL){
                q.push(curr->right);
            }
            
            if(Prev != NULL){
                Prev->next = curr;
            }
        }
        Prev=curr;
    }
    return root;
}

int main(){
    return 0;
}