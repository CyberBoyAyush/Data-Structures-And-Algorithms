// First and Last Position of an Element In Sorted Array
// https://www.naukri.com/code360/problems/first-and-last-position-of-an-element-in-sorted-array_1082549?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <bits/stdc++.h> 
#include<vector>
using namespace std;

int firstOccurence(vector<int>& arr, int size,int key){
    int start = 0;
    int end = size - 1;
    int mid = start + (end-start)/2;
    int ans = -1;
    while(start<=end){
        if(key==arr[mid]){
            ans = mid;
            end = mid-1;
        }
        else if(key>arr[mid]){
            start = mid + 1;
        }
        else if(key<arr[mid]){
            end = mid - 1;
        }
        mid = start + (end-start)/2;
    }
    return ans;
}
int lastOccurence(vector<int>& arr, int size,int key){
    int start = 0;
    int end = size - 1;
    int mid = start + (end-start)/2;
    int ans = -1;
    while(start<=end){
        if(key==arr[mid]){
            ans = mid;
            start = mid+1;
        }
        else if(key>arr[mid]){
            start = mid + 1;
        }
        else if(key<arr[mid]){
            end = mid - 1;
        }
        mid = start + (end-start)/2;
    }
    return ans;
}

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    pair <int,int> p;
    p.first = firstOccurence(arr,n,k);
    p.second = lastOccurence(arr,n,k);

    return p;
}