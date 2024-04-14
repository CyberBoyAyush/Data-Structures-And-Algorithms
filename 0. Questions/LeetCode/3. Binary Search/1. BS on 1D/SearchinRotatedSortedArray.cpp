// Search in Rotated Sorted Array
// https://leetcode.com/problems/search-in-rotated-sorted-array/

#include<vector>
using namespace std;
class Solution {
 public:
  int search(vector<int>& arr, int k) {
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    while (low <= high) {
      int mid = (low + high) / 2;
      if (arr[mid] == k) {
        return mid;
      }

      // left part is sorted
      if (arr[mid] >= arr[low]) {
        if (arr[low] <= k && k <= arr[mid]) {
          high = mid - 1;
        } else {
          low = mid + 1;
        }
      }
      // right part is sorted
      else {
        if (arr[mid] <= k && k <= arr[high]) {
          low = mid + 1;
        } else {
          high = mid - 1;
        }
      }
    }
    return -1;
  }
};