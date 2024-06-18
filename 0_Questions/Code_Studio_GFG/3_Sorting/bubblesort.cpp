// https://www.naukri.com/code360/problems/bubble-sort_624380?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include<iostream>
#include<vector>
using namespace std;
void bubbleSort(vector<int>& arr, int n) 
{
   for(int i = 1;i<=n;i++){
       int didSwap = 0;
       for(int j = 0;j<n-i;j++){
           if(arr[j]>arr[j+1]){
               swap(arr[j],arr[j+1]);
               didSwap = 1;
           }
       }
       if(didSwap==0){
           break;
       }
   }
}
