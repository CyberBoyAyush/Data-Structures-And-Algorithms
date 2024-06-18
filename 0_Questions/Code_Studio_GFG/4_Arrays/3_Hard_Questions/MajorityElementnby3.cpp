// Majority Element n/3 times
// https://www.naukri.com/code360/problems/majority-element_6915220?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
#include<vector>
using namespace std;
#include<iostream>
#include<bits/stdc++.h>
vector<int> majorityElement(vector<int> v) {

    // Write your code here

    vector<int>ans;

    map<int,int>store;

    for(int i=0; i<v.size(); i++){

        store[v[i]]++;

    }

    for(auto x:store){

        if(x.second>v.size()/3)

         ans.push_back(x.first) ;

    }

    return ans;

}