// https://www.naukri.com/code360/problems/insertion-sort_624381?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include<vector>
#include<iostream>
using namespace std;

#include<bits/stdc++.h>
void insertionSort(int arr[], int n)
{
   for(int i = 0; i<n;i++){
       int j = i;
       while(j>0 && arr[j-1]>arr[j]){

           // Swap is not working here so we hard coded swap
           int temp=arr[j-1];

            arr[j-1]=arr[j];

            arr[j]=temp;
           j--;
       }
   }
}