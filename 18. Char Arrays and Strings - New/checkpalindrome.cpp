#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(char* ch){
    int s = 0;
    int e = strlen(ch) - 1;
    while(s<e){
        if(ch[s]!=ch[e]){
            return false;
        }
         s++;
         e--;
    }
    return true;
}
int main(){
    char ch[100];

    cin>>ch;

    if(isPalindrome(ch)){
        cout<<"Palindrome";
    }
    else{
        cout<<"not palindrome";
    }
return 0;
}