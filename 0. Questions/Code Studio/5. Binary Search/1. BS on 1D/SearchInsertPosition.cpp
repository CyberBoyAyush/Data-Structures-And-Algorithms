// Search Insert Position
// https://www.naukri.com/code360/problems/algorithm-to-find-best-insert-position-in-sorted-array_839813?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

/*
    Time Complexity - O(log N)
    Space Complexity - O(1)

    Where 'N' is the size of the array.
*/
#include<vector>
using namespace std;
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