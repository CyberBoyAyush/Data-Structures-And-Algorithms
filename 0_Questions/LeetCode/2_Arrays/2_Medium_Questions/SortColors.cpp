// Sort Colors
// https://leetcode.com/problems/sort-colors/
#include<vector>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& arr) {
        int n = arr.size();
        int low = 0;
        int mid = 0;
        int high = n-1;

        while(mid <= high){
            if(arr[mid]==0){
                swap(arr[low],arr[mid]);
                low++;
                mid++;
            }
            else if(arr[mid]==1){
                mid ++;
            }
            else{
                swap(arr[mid],arr[high]);
                high --;
             }
        }  
    }
};