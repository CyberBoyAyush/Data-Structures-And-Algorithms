// Creation of Binary Tree using Recursion
#include<bits/stdc++.h>
using namespace std;
// For Node Creation
class Node{
    public:
    int data;
    Node* left, *right;

    //constructor
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

// Creation Of Binary Tree
Node * BinaryTree(){
    int x;
    cin>>x;

    // Base Case
    if(x==-1){
        return NULL;
    }

    Node * temp = new Node(x);
    cout<<"Enter the left child of "<<x<< " : "<<endl;
    temp->left = BinaryTree();
    cout<<"Enter the right child of "<<x<< " : "<<endl;
    temp->right = BinaryTree();
    return temp;
}


int main(){
    cout<<"Enter root node: "<<endl;
    Node * root;
    root = BinaryTree();
    return 0;
}