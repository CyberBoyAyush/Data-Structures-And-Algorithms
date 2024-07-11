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

// get height func
int getheight(Node* root){
    if(!root){
        return 0;
    }

    return root->height;
}

// balancing check func
int getBalance(Node* root){
    return getheight(root->left) - getheight(root->right);
}

// rightRotation func
Node* rightRotation(Node* root){
    Node* child = root->left;
    Node* childright = child->right;

    child->right = root;
    root->left = childright;

    // updating heights of root and child
    root->height = 1 + max(getheight(root->left) , getheight(root->right));
    child->height = 1 + max(getheight(child->left) , getheight(child->right));

    return child;
}

// leftRotation func
Node* leftRotation(Node* root){
    Node* child = root->right;
    Node* childleft = child->left;

    child->left = root;
    root->right = childleft;

    // updating heights of root and child
    root->height = 1 + max(getheight(root->left) , getheight(root->right));
    child->height = 1 + max(getheight(child->left) , getheight(child->right));

    return child;
}

Node* insert(Node* root,int key){
    // doesnt exists
    if(!root){
        return new Node(key);
    }

    //exists
    if(key<root->data){
        //left side
        root->left = insert(root->left,key);
    }

    if(key>root->data){ // right
        root->right = insert(root->right,key);
    }

    else{
        return root; // duplicate value hai
    }

    // updating height
    root->height = 1 + max(getheight(root->left),getheight(root->right));

    // balancing check
    int balance = getBalance(root);

    // Unbalacing Cases
    // Left Left Case
    if(balance > 1 && key < root->left->data){
        return rightRotation(root);
    }
    // Right Right Case
    else if(balance < -1 && key > root->right->data){
        return leftRotation(root);
    }
    // Left Right Case
    else if(balance > 1 && key > root->left->data){
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }
    // Right Left Case
    else if(balance < -1 && key < root->right->data){
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }
    // No Unbalancing
    else{
        return root;
    }
}


//preorder

void preoder(Node* root){
    if(!root)
    return ;

    // NLR
    cout<<root->data<<" ";
    preoder(root->left);
    preoder(root->right);
}

int main(){
  Node* root = NULL;

  root = insert(root,10);
  root = insert(root,20);
  root = insert(root,30);

  // printing
  cout<<"Preorder : "<<endl;
  preoder(root);
  return 0;
}