// Search Insert Position
// https://leetcode.com/problems/search-insert-position/#:~:text=Search%20Insert%20Position%20%2D%20LeetCode&text=Given%20a%20sorted%20array%20of,(log%20n)%20runtime%20complexity.

#include<vector>
using namespace std;
class Solution {
public:

int searchInsert(vector<int>& arr, int m)
{
    int lo = 0;
    int hi = arr.size() - 1;
    int ans = -1;

    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;

        // Check if element is present.
        if (arr[mid] == m)
        {
            return mid;
        }

        // Check in left half.
        if (arr[mid] > m)
        {
            hi = mid - 1;
            ans = mid;
        }
        // Check in right half.
        else
        {
            lo = mid + 1;
        }
    }

    if (ans == -1)
    {
        ans = arr.size();
    }

    return ans;
    }
};