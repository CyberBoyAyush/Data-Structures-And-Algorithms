#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    // Max Heap --> Priortize Max number
    priority_queue<int> maxi;

    // Min Heap --> Priortize Min number
    priority_queue<int, vector <int>, greater<int>> mini;

    maxi.push(2);
    maxi.push(1);
    maxi.push(4);
    maxi.push(6);

    int n = maxi.size();
    for(int i = 0; i<n; i++){
        cout<<maxi.top()<<endl;
        maxi.pop();
    }

    cout<<endl;
    cout<<endl;


    mini.push(2);
    mini.push(1);
    mini.push(4);
    mini.push(6);

    int z = mini.size();
    for(int i = 0; i<z; i++){
        cout<<mini.top()<<endl;
        mini.pop();
    }
    }