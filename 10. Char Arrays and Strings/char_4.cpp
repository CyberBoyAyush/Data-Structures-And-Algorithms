#include<iostream>
using namespace std;

// Convert uppercase to lowercase.
int loCase(char ch){
    if(ch >= 'a' && ch<= 'z'){
        return ch;
    }
    else{
        char temp = ch - 'A' + 'a';
        return temp;
    }
}

// Check Palindrome.
bool checkPalindrome(char arr[],int n){
    int s = 0;
    int e = n-1;

    while(s<=e){
        if(arr[s]!=arr[e]){
            return 0;
        }
        else{
            s++;
            e--;
        }
        return 1;
    }
}



int getLength(char arr[]){
    int count = 0;
    for(int i = 0; arr[i] != '\0' ;i++){
        count ++;
    }
    return count;
}

int main(){
    char name[20];
    cout<<"Enter Your Name:"<<endl;
    cin>>name;
    
    int length = getLength(name);
    cout<< checkPalindrome(name,length);

    
}