#include<iostream>
using namespace std;

// Reversing char Array.

void swapArray(char arr[],int n){
    int s = 0;
    int e = n-1;
    while(s<e){
        swap(arr[s++],arr[e--]);
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

    swapArray(name, length);

    cout<<name;

    
}