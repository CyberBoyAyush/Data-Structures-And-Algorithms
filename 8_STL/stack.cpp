#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    stack<string> s;

    s.push("Ayush");
    s.push("Sharma");
    s.push("Boy");

    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;


}
