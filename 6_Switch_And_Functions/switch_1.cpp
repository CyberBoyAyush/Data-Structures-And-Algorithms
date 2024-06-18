#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    switch(n){
        case 1: cout<<"first"<<endl;
        break;
        case 2: cout<<"second"<<endl;
        break;
        case 3: cout<<"third"<<endl;
        break;
        default: cout<<"this is default case"<<endl;
        break;
    }
}