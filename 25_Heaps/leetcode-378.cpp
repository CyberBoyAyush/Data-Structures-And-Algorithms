// Leetcode 378
// Find kth smallest ement in a matrix

#include<bits/stdc++.h>
using namespace std;
#define fo(i,n) for(int i = 0 ;i<n ;i++)


// Priority Queue Min Heap with index pushing in pairs

// class Solution {
// public:
//     int kthSmallest(vector<vector<int>>& mat, int k) {
//         int n = mat.size();
//         // vector
//         vector<pair<int, pair<int, int>>> temp;

//         // pushing values of first column in vector
//         for (int i = 0; i < n; i++) {
//             temp.push_back(make_pair(mat[i][0], make_pair(i, 0)));
//         }

//         // creating min heap (values,location in pair) in O(N) time
//         priority_queue<pair<int, pair<int, int>>,
//                        vector<pair<int, pair<int, int>>>,
//                        greater<pair<int, pair<int, int>>>>
//             pq(temp.begin(), temp.end());

//         int ans;
//         pair<int, pair<int, int>> element;
//         int i, j;
//         while (k--) {
//             element = pq.top();
//             pq.pop();
//             ans = element.first;       // value
//             i = element.second.first;  // accessing the row
//             j = element.second.second; // accessing the col

//             // pushing the next value in row
//             if (j + 1 < n) {
//                 pq.push(make_pair(mat[i][j + 1], make_pair(i, j + 1)));
//             }
//         }
//         return ans;
//     }
// };

// Binary Search on Ans
class Solution {
public:
    int kthSmallest(vector<vector<int>>& arr, int k) {

        int n = arr.size();
        int l = arr[0][0], r = arr[n - 1][n - 1], ans = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                auto it = upper_bound(arr[i].begin(), arr[i].end(),mid); // counting elements less than equal to mid
                cnt += (it - arr[i].begin());
            }
            if (cnt >= k) { 
                // if number of elements smaller than/ equal to are greater
                // than equal to k, then mid can be our answer
                ans = mid;
                r = mid - 1;
            } else
                l = mid + 1;
        }
        return ans;
    }
}; 