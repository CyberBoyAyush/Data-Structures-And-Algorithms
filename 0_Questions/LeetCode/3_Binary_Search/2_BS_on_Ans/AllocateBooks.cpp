// Allocate Books
// https://www.naukri.com/code360/problems/allocate-books_1090540?utm_source=youtube&utm_medium=affiliate&utm_campaign=codestudio_Striver_BinarySeries

#include<vector>
#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
#include<climits>
using namespace std;
int student(vector<int>& arr,int mid ){
    int student = 1;
    int pagecount = 0;
    int n = arr.size();

    for(int i = 0; i<n; i++){
        if(pagecount+arr[i]<=mid){
            pagecount+=arr[i];
        }
        else{
            student++;
            pagecount = arr[i];
        }
    }
    return student;
}

int findPages(vector<int>& arr, int n, int m) {
    if (m > n) return -1;
    int low = *max_element(arr.begin(),arr.end());
    int high = accumulate(arr.begin(),arr.end(),0);
    while(low<=high){
        int mid = (low + high)/2;
        int studentcnt = student(arr,mid);
        if(studentcnt>m){
            low = mid + 1;
        }
        else{
           high = mid -1;

        }
    }
    return low;
}