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

//insert a node in Bst
Node* Insert(Node* root, int val){
    if(root==NULL){
        return new Node(val);
    }
    if(val < root->data){
        root->left = Insert(root->left,val);
    }else{
        root->right=Insert(root->right,val);
    }
    return root;
}
Node* BuildBST(vector<int> arr){
    Node* root=NULL;
    for(int val: arr){
        root= Insert(root,val);
    }
    return root;
}

void Inorder(Node* root, vector<int> &arr){
    if(root == NULL){
        return;
    }

    Inorder(root->left,arr);
    arr.push_back(root->data);
    Inorder(root->right,arr);

}

Node* BuildBSTFromSortedSequence(vector<int> arr, int st, int end){
    if(st > end){
        return NULL;
    }
    int mid=st+ (end-st)/2;
    Node* root=new Node(arr[mid]);

    root->left = BuildBSTFromSortedSequence(arr,st,mid-1);
    root->right = BuildBSTFromSortedSequence(arr,mid+1,end);

    return root;
}

Node* Merge2BST(Node* root1, Node* root2){
    vector<int> arr1,arr2;
    Inorder(root1, arr1);
    Inorder(root2, arr2);

    vector<int> temp; // final inorder BST: sorted sequence

    int i=0,j=0;
    while(i< arr2.size() && j< arr2.size()){
        if(arr1[i] < arr2[j]){
            temp.push_back(arr1[i++]);
        }else{
            temp.push_back(arr2[j++]);
        }
    }
    while(i<arr1.size()) {
        temp.push_back(arr1[i++]);
    }
    while(j< arr2.size()) {
        temp.push_back(arr2[j++]);
    }

    return BuildBSTFromSortedSequence(temp, 0, temp.size()-1);
}
int main(){
    vector<int> arr1={8,2,1,10};
    vector<int> arr2={5,3,0};

    Node* root1 = BuildBST(arr1);
    Node* root2 = BuildBST(arr2);
    Node* root=Merge2BST(root1,root2);
    vector<int> seq;
    Inorder(root,seq);
    for(int val: seq){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}