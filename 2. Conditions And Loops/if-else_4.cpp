#include<iostream>
using namespace std;

int main(){
    char ch;
    cout<<"Enter Your Character"<<endl;
    cin>>ch;

    if(ch>=97 && ch<=122){
        cout<<"This is a lower case ch"<<endl;
    }
    else if(ch>=65 && ch<=90){
        cout<<"This is a upper case ch"<<endl;
    }
    else if(ch>=48 && ch<=57){
        cout<<"This is numeric"<<endl;

    }
    else{
        cout<<"This is a symbol"<<endl;
    }
}