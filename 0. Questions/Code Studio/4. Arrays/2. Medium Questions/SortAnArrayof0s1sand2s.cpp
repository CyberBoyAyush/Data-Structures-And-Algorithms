// Sort An Array of 0s, 1s and 2s
//https://www.naukri.com/code360/problems/sort-an-array-of-0s-1s-and-2s_892977?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
#include<vector>
#include<string>
#include <bits/stdc++.h> 
using namespace std;
void sortArray(vector<int>& arr, int n)
{
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
