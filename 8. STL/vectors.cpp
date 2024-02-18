#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v; // Intializing a vector(dynamic array)
    cout<<"Capacity "<<v.capacity()<<endl; // Check thee capacity of vector(Total elemnts can be entered int his array)
    cout<<"Size "<<v.size()<<endl; // Size of array--> Total elements there are in array
    v.push_back(1); // Enter the value in vector
    cout<<"Capacity "<<v.capacity()<<endl;
    cout<<"Size "<<v.size()<<endl;
    v.push_back(2);
    cout<<"Capacity "<<v.capacity()<<endl;
    cout<<"Size "<<v.size()<<endl;
    v.push_back(3);
    cout<<"Capacity "<<v.capacity()<<endl;
    cout<<"Size "<<v.size()<<endl;

    for(int i = 0; i<v.size(); i++){
        cout<<v[i]<<" ";
        cout<<endl;
    }

    v.pop_back(); // Rmeove the last value of vector
    for(int i = 0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
}