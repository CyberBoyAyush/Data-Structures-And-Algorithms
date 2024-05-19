// Check Sorted Array
// https://www.naukri.com/code360/problems/ninja-and-the-sorted-check_6581957?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
#include<vector>
using namespace std;
int isSorted(int n, vector<int> arr) {
   for(int i = 1; i<n;i++){
       if(arr[i]<arr[i-1]){
           return false;
       } 
   }
    return true;
}
