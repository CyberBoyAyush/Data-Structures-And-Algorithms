// Non Overalpping Intervals
// Leetcode : https://leetcode.com/problems/non-overlapping-intervals/

// Approach -> Greedy
// TC - O(NlogN)
// SC - O(1)

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // step 1 : sorting on start time basis
        sort(intervals.begin(),intervals.end());

        int count = 0;

        int n = intervals.size();

        int i = 0, j = 1;
        while(j<n){
            vector<int> currInterval = intervals[i];
            vector<int> nextInterval = intervals[j];

            // current start and current end
            int cs = currInterval[0];
            int ce = currInterval[1];

            // next start and next end
            int ns = nextInterval[0];
            int ne = nextInterval[1];

            // step 2 : cases

            if(ce <= ns){
                // no overlapping
                i = j;
                j++;
            }
            else if(ce <= ne){
                // overlapping hai
                // next end bada hai we will dlete it
                j++;
                count++;
            }
            else if(ce > ne){
                // overlapping hai
                // current wala bada hai remove it
                i = j;
                j++;
                count++;
            }
        }
        return count;
    }
};