#include<iostream>
using namespace std;

bool checkPalindrome(string &str,int i,int j){
    if(i>j){
        return 0;
    }
    if(str[i]==str[j]){
        return true;
    }
    else{
        return false;
    }
    checkPalindrome(str,i++,j--);
}

int main(){
    string str = "madam";

    if(checkPalindrome(str,0,str.length()-1)){
        cout<<"Palindrome"<<endl;
    }
    else{
        cout<<"Not Palindrome"<<endl;
    }
}