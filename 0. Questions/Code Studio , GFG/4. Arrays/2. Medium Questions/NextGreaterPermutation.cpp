// Next Greater Permutation
// https://www.naukri.com/code360/problems/next-greater-permutation_6929564?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
vector<int> nextGreaterPermutation(vector<int> &A) {
   int index = -1;
   int n = A.size();

   for(int i = n-2; i>=0; i--){
       if(A[i]<A[i+1]){
           index = i;
           break;
       }
   }
   if(index == -1){
       reverse(A.begin(),A.end());
       return A;
   }
   for(int i = n-1 ; i>= index ; i--){
       if(A[i]>A[index]){
           swap(A[i],A[index]);
           break;
       }
   }
   reverse(A.begin() + index +1, A.end());
   return A;
}


// We do have a prebuilt function called next_permutation for this.