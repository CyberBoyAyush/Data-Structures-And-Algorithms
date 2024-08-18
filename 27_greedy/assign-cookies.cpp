// Assign Cookies
// Leetcode : https://leetcode.com/problems/assign-cookies/

// Approach -> Greedy
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // sort both grred and size array
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int n = g.size(), m = s.size();

        int i = 0, j = 0;
        while(i <n && j < m){
            if(s[j] >= g[i]){
                i++;
            }
            j++;
        }

        return i;
    }
};