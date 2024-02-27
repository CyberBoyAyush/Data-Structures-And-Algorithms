#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// In this question we start from 0 index and swap the first number wiwth last number and increment s and decrement e

vector<int> reverse(vector<int> v){
    int s = 0;
    int e = v.size() - 1;

    while(s<=e){
        swap(v[s],v[e]);
        s++;
        e--;

    }
    return v;
}


void printArray(vector<int> v){
    for(int i = 0; i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> v;
    v.push_back(11);
    v.push_back(9);
    v.push_back(5);
    v.push_back(1);

    printArray(v);
    vector<int> ans = reverse(v);
    printArray(ans);



    return 0;
}