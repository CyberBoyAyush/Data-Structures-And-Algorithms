// 912. Sort an Array -- Merge Sort
//https://leetcode.com/problems/sort-an-array/description/
#include<vector>
#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;
class Solution {
public:

void merge(vector < int > & arr,int low,int mid ,int high){
    vector < int > temp;
    int left = low;
    int right = mid + 1;

    while(left<=mid && right <= high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }

    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right <= high){
        temp.push_back(arr[right]);
        right++;
    }

    for(int i = low ; i<=high; i++){
        arr[i] = temp[i-low];
    }
}


void mS(vector < int > & arr,int low,int high){
    if(low==high){
        return ;
    }
    int mid = (low + high)/2;
    mS(arr,low,mid);
    mS(arr,mid + 1, high);
    merge(arr,low,mid,high);
}
    vector<int> sortArray(vector<int>& arr) {
        mS(arr,0,arr.size()-1);
        return arr;
    }
};