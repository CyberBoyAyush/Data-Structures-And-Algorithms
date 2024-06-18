// Function for finding Next Smallest Element in Right
#include<bits/stdc++.h>
using namespace std;

vector<int> getNSR(vector<int>& arr, int n){
        vector<int> res(n);
        stack<int> st;

        for(int i = n-1; i>=0; i--){
            if(st.empty()) res[i] = n;

            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            res[i] = st.empty() ? n:st.top();
            st.push(i);
        }
        return res;
    }