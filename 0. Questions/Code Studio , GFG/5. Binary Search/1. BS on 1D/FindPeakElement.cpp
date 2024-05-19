// Find Peak Element
// https://www.naukri.com/code360/problems/find-peak-element_1081482?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include<vector>
using namespace std;

int findPeakElement(vector<int> &arr) {
  int n = arr.size();
  if (n == 1)
    return 0;
  if (arr[0] > arr[1])
    return 0;
  if (arr[n - 1] > arr[n - 2])
    return n - 1;
  int low = 1, high = n - 2; // bcz we also check for 0 and n-1
  while (low <= high) {
    int mid = (low + high) / 2;
    if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
      return mid;
    } else if (arr[mid] > arr[mid - 1]) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return -1;
}
