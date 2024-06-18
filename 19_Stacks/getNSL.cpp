// Function for finding Next Smallest Element in Left
#include<bits/stdc++.h>
using namespace std;

vector<int> getNSL(vector<int>& arr, int n){
        vector<int> res(n);
        stack<int> st;

        for(int i = 0; i<n ;i++){
            if(st.empty()) res[i] = -1;

            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            res[i] = st.empty() ? -1:st.top();
            st.push(i);
        }
        return res;
    }