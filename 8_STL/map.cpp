#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int mian(){
    map<int,int> m;

    // Inserting values in maps
    m[1] = {2};
    m.emplace(3,4);
    m.insert({5,6});

    // for(auto it : m){
    //     cout<<it.first<<" "<<it.second<<endl;
    // }

    cout<<m[1]<<endl;

}