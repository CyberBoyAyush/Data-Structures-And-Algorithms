// Implementation of Binary Tree using Queue
#include<bits/stdc++.h>
using namespace std;

//Node Class
class Node{
    public:
    int data;
    Node* left, *right;

    // constructor
    Node(int val){
        data = val;
        left = right = nullptr;
    }
};

int main(){
    int x;
    cout<< "Entr The Value of Root: "<<endl;
    cin>>x;

    int first,second;
    // Queue for address maintaining
    queue<Node*> q;
    //root node creation
    Node* root = new Node(x);
    q.push(root);

    //Building Tree
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        //left node
        cout<< "Enter the value left child of " << temp->data<<": "<<endl;
        cin>>first;
        if(first != -1){
            temp->left = new Node(first);
            q.push(temp->left);
        }

        //right node
        cout<< "Enter the value right child of " << temp->data<<": "<<endl;
        cin>>second;
        if(second != -1){
            temp->right = new Node(second);
            q.push(temp->right);
        }
    }
    return 0;
}