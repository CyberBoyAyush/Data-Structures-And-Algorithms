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
        return nullptr;
    }

    Node * temp = new Node(x);
    cout<<"Enter the left child of "<<x<< " : "<<endl;
    temp->left = BinaryTree();
    cout<<"Enter the right child of "<<x<< " : "<<endl;
    temp->right = BinaryTree();
    return temp;
}

// Traversal In TREE
// PreOrder
void PreorderTrav(Node* root){
    // Preorder Traversal is NLR
  if(root == nullptr){
      return;
  }
  
  // Node
  cout<<root->data;
  
  //Left
  PreorderTrav(root->left);
  
  //Right
  PreorderTrav(root->right);
}

// Inorder
void inorderTrav(Node* root){
    // Inorder Traversal is LNR
  if(root == nullptr){
      return;
  }
  
  
  //Left
  inorderTrav(root->left);
  
  // Node
  cout<<root->data;
  
  //Right
  inorderTrav(root->right);
}

// PostOrder
void PostorderTrav(Node* root){
    // Postorder Traversal is LRN
  if(root == nullptr){
      return;
  }
  
  
  //Left
  PostorderTrav(root->left);
  
  //Right
  PostorderTrav(root->right);

  // Node
  cout<<root->data;
}


int main(){
    cout<<"Enter root node: "<<endl;
    Node * root;
    root = BinaryTree();

    cout<<"preOrder"<<endl;
    PreorderTrav(root);
    cout<<endl;
    cout<<"inOrder"<<endl;
    inorderTrav(root);
    cout<<endl;
    cout<<"PostOrder"<<endl;
    PostorderTrav(root);
    cout<<endl;


    return 0;

}