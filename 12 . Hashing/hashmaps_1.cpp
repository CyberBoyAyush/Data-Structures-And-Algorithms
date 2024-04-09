#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    int arr[n];
    
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }

    map <int,int> mpp;
    for(int i = 0; i<n; i++){
        mpp[arr[i]]++;
    }

    // Iterating in map
    for( auto it: mpp){
        cout<<it.first<<"-->" <<it.second<<endl;
    }

    //fetch
    int num;
    cin>>num;
    cout<< " HAsh : "<<mpp[num];
}