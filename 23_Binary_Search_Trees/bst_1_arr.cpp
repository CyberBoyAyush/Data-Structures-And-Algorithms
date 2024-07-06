#include<bits/stdc++.h>
using namespace std;


//Node 
class Node{
    public:
    int data;
    Node* left, *right;

    //constructor
    Node(int val){
        data = val;
        left = right = nullptr;
    }
};

Node * insert(Node* root,int target){
    //base case
    if(!root){
        Node* temp = new Node(target);
        return temp;
    }

    //recursion
    if(target<root->data){
        root->left = insert(root->left,target);
    }
    else{
        root->right = insert(root->right,target);
    }

    return root;
}


// inorder traversal
void inorder(Node* root){
    // LNR
    if(!root){
        return;
    }

    inorder(root->left);

    cout<<root->data<<" ";

    inorder(root->right);
}

//search func
bool search(Node* root,int target){
    if(!root){
        return 0;
    }

    if(root->data == target){
        return 1;
    }

    if(root->data>target){
        return search(root->left,target);
    }
    else{
        return search(root->right,target);
    }
}

// Function to delete a node from BST.
Node *deleteNode(Node *root, int target) {
    // Base Case
    if(!root){
        return NULL;
    }
    
    //left
    if(root->data > target){
        root->left = deleteNode(root->left,target);
        return root;
    }
    
    // right
    else if(root->data < target){
        root->right = deleteNode(root->right,target);
        return root;
    }
    
    else{
        // root->data == target
        // node we delete is leaf node
        if(!root->left && !root->right){
            delete root;
            return NULL;
        }
        
        // node we delete has one child
        else if(!root->left){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        
        else if(!root->right){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        
        // both child exists
        else{
            // find greater element from left or smaller from right we are finding greater from left
            Node* child = root->left;
            Node* parent = root;
            
            //right most 
            while(child->right){
                parent = child;
                child = child->right;
            }
            
            // case where root and parent is diff
            if(root!=parent){
                parent->right = child->left;
                child->left = root->left;
                child->right = root->right;
                delete root;
                return child;
            }
            
            // other case
            else{
                child->right = root->right;
                delete root;
                return child;
            }
        }
    }
}

int main(){
    int arr[] = {6,7,4,3,9,12,33,45,1,0};

    Node* root = nullptr;

    for(int i = 0;i<10; i++){
        root = insert(root,arr[i]);
    }

    // tarversal
    inorder(root);


    //search
    int target = 100;
    cout<<endl;
    cout<< search(root,target);

    return 0;
}