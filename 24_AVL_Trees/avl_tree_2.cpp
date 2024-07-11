#include<bits/stdc++.h>
using namespace std;
#define fo(i,n) for(int i = 0 ;i<n ;i++)

class Node{
    public:
    int data;
    Node* left,*right;
    int height;

    //constructor
    Node(int val){
        data = val;
        left = right = nullptr;
        height = 1;
    }
};

int getHeight(Node* root){
    if(!root){
        return 0;
    }
    
    return root->height;
}

int getBalance(Node* root){
    return getHeight(root->left) - getHeight(root->right);
}

// rightRotation func
Node* rightRotation(Node* root){
    Node* child = root->left;
    Node* childright = child->right;

    child->right = root;
    root->left = childright;

    // updating heights of root and child
    root->height = 1 + max(getHeight(root->left) , getHeight(root->right));
    child->height = 1 + max(getHeight(child->left) , getHeight(child->right));

    return child;
}

// leftRotation func
Node* leftRotation(Node* root){
    Node* child = root->right;
    Node* childleft = child->left;

    child->left = root;
    root->right = childleft;

    // updating heights of root and child
    root->height = 1 + max(getHeight(root->left) , getHeight(root->right));
    child->height = 1 + max(getHeight(child->left) , getHeight(child->right));

    return child;
}

Node* deleteNode(Node* root, int key)
{
    // root does not exists
    if(!root){
        return nullptr;
    }
    
    // root exists
    if(key<root->data){
        root->left = deleteNode(root->left,key);
    }
    else if(key>root->data){
        root->right = deleteNode(root->right,key);
    }
    else{
        // leaf node
        if(!root->left && !root->right){
            delete root;
            return NULL;
        }
        // only one child
            // 1-> only left child
        else if(root->left && !root->right){
            Node* temp = root->left;
            delete root;
            return temp;
        }
            // 2-> only right child
        else if(!root->left && root->right){
            Node* temp = root->right;
            delete root;
            return temp;
        }    
        // both child exists
        else{
            Node* curr = root->right;
            
            while(curr->left){
                curr = curr->left;
            }
            
            root->data = curr->data;
            root->right = deleteNode(root->right,curr->data);
        }
    }
    
    // update height
    root->height = 1 + max(getHeight(root->left) , getHeight(root->right));
    
    // check the balancing
    int balance = getBalance(root);
    
    if(balance>1){
        // LL
        if(getBalance(root->left)>=0){
            return rightRotation(root);
        }
        // LR
        else{
            root->left = leftRotation(root->left);
            return rightRotation(root);
        }
    }
    
    else if(balance < -1){
        // RR
        if(getBalance(root->right)<=0){
            return leftRotation(root);
        }
        // RL
        else{
            root->right = rightRotation(root->right);
            return leftRotation(root);
        }
    }
    
    else{
        return root;
    }
}