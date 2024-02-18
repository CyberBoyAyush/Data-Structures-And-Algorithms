#include<iostream>
using namespace std;
#include<bits/stdc++.h>


int main(){
    array<int,4> a = {1,2,3,4};
    int size = a.size();
    for(int i = 0; i<size;i++){
        cout<<a[i]<<endl;
    }
    cout<<a.at(2)<<endl; //using at method we can check number at particular index
    cout<<a.front()<<endl; // front gives us first element in the array
    cout<<a.back()<<endl; // gives us last elemt of the array
}