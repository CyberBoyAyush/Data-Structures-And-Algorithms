#include<iostream>
using namespace std;

int main(){
    int a;
    cout<<"Enter Your Number:"<<endl;
    cin>>a;

    if (a>0){
        cout<<"Your Number Is Positive";
    }
    else{
        if (a<0){
            cout<<"Your Number is Negative";
        }
        else{
            cout<<"Your Number is 0.";
        }
    }
}