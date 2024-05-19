// Single Element in a Sorted Array
// https://www.naukri.com/code360/problems/unique-element-in-sorted-array_1112654?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
#include<vector>
using namespace std;
int singleNonDuplicate(vector<int>& arr) {

    int left = 0;

    int right = arr.size() - 1;

 

    while (left < right) {

        int mid = left + (right - left) / 2;

 

        // Ensure mid is even-indexed

        if (mid % 2 != 0) {

            mid--;

        }

 

        // Check if the non-duplicate is on the left or right

        if (arr[mid] == arr[mid + 1]) {

            left = mid + 2;

        } else {

            right = mid;

        }

    }

 

    return arr[left];

}