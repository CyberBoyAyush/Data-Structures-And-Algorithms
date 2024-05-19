#include<iostream>
using namespace std;

void reverse(string &name,int i,int j){
    if(i>j){
        return ;
    }
    swap(name[i],name[j]);
    i++;
    j--;
    reverse(name,i,j);
    
}

int main(){
    string name = "Ayush";
    int len = name.length();
    int i = 0;
    int j = len-1;

    reverse(name,i,j);
    cout<<name;
}