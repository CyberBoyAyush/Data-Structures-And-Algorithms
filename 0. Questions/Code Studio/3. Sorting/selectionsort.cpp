// https://www.naukri.com/code360/problems/selection-sort_624469?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
#include<vector>
#include<iostream>
using namespace std;
void selectionSort(vector<int>&arr) {
    for(int i = 0; i<arr.size();i++){
        int mini = i;
        for(int j = i;j<=arr.size()-1;j++){
            if(arr[j]<arr[mini]){
                mini = j;
            }
        }
        swap(arr[mini],arr[i]);
    }
}