//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data%10; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* reverse(Node* head){
        Node* temp = head;
        Node* prev = nullptr;
        
        while(temp!=nullptr){
            Node* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp=front;
        }
        return prev;
    }
    
    int helper(Node* temp){
        if(temp!=nullptr){
            return 1; // Initial carry
        }
        
        int carry = helper(temp->next);
        temp->data = temp->data + carry;
        if(temp->data < 10){
            return 0; // carry 0 break it
        }
        
        temp->data = 0;
        return 1; // carry = 1
        
    }
    
    Node* addOne(Node *head) 
    {
        // head = reverse(head);
        // Node* temp = head;
        // int carry = 1;
        // while(temp!=nullptr){
        //     temp->data = temp->data + carry;
        //     if(temp->data<10){
        //         carry = 0;
        //         break;
        //     }
        //     else{
        //         temp->data = 0;
        //         carry = 1;
        //     }
            
        //     temp = temp->next;
        // }
        
        // if(carry==1){
        //     Node * newNode = new Node(1);
        //     head = reverse(head);
        //     newNode->next = head;
        //     return newNode;
        // }
        
        // head = reverse(head);
        // return head;
        
        // Revursive
        int carry = helper(head);
        if(carry == 1){
            Node * newNode = new Node(1);
            head = reverse(head);
            newNode->next = head;
            return newNode;
        }
        
        return head; // if carry == 0
        
        
    }
};


//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends