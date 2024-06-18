// Largest Element in the Array
// https://www.naukri.com/code360/problems/largest-element-in-the-array-largest-element-in-the-array_5026279?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <bits/stdc++.h> 
#include<vector>
using namespace std;
int largestElement(vector<int> &arr, int n) {
    int num = arr[0];
    for(int i = 0; i<n;i++){
        if(arr[i]>num){
            num = arr[i];
        }
    }
    return num;
}
