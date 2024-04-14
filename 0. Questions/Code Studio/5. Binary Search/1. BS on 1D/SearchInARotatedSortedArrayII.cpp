// Search In A Rotated Sorted Array II
// https://www.naukri.com/code360/problems/search-in-a-rotated-sorted-array-ii_7449547?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
#include<vector>
using namespace std;
bool searchInARotatedSortedArrayII(vector<int>&arr, int k) {
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
