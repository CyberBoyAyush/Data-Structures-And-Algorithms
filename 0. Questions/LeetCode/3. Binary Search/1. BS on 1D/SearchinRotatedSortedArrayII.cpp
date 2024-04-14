// Search in Rotated Sorted Array II
// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
#include<vector>
using namespace std;
class Solution {
public:
    bool search(vector<int>& arr, int k) {
        int n = arr.size();
    int low = 0;
    int high = n-1;
    while(low<=high){
        int mid = (low + high)/2;
        if(arr[mid]==k){
            return 1;
        }
         if (arr[low]== arr[mid] && arr[high] == arr [mid] ) {

            low++;

            high--;

            continue;

        }
        // left part is sorted
        if(arr[mid]>=arr[low]){
            if(arr[low]<=k && k<=arr[mid]){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        // right part is sorted
        else{
            if(arr[mid]<=k && k<=arr[high]){
                low = mid +1;
            }
            else{
                high = mid - 1;
            }
        }
       
    }
    return 0; 
    }
};