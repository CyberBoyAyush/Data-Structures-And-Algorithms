// Rotate array
// https://www.naukri.com/code360/problems/rotate-array_1230543?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

vector<int> rotateArray(vector<int>arr, int k) {
    int n=arr.size();

        k=k%n;

        

        reverse(arr.begin(),arr.begin()+k);

        reverse(arr.begin()+k,arr.end());

        reverse(arr.begin(),arr.end());

 

        return arr;
}
