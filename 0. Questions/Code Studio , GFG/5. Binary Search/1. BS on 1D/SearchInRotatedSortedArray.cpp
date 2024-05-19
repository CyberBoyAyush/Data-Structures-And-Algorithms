// Search In Rotated Sorted Array
// https://www.naukri.com/code360/problems/search-in-rotated-sorted-array_1082554?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include<vector>
using namespace std;
int search(vector<int>& arr, int n, int k)
{
    int low = 0;
    int high = n-1;
    while(low<=high){
        int mid = (low + high)/2;
        if(arr[mid]==k){
            return mid;
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
    return -1; 
}
