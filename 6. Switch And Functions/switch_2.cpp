#include<iostream>
using namespace std;

int main(){
    int a,b;
    cout<<"Enter The value of a"<<endl;
    cin>>a;
    cout<<"Enter The value of b"<<endl;
    cin>>b;

    char operation;
    cout<<"Enter The Operation + - * / %"<<endl;
    cin>>operation;

    switch (a,b,operation)
    {
    case '+': 
        cout<<a+b<<endl;;
        break;
    case '-': 
        cout<<a-b<<endl;;
        break;
    case '*': 
        cout<<a*b<<endl;;
        break;
    case '/': 
        cout<<a/b<<endl;;
        break;
    case '%': 
        cout<<a%b<<endl;;
        break;
    

    }

}