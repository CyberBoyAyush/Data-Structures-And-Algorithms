//  Subarrays with XOR ‘K’
// https://www.naukri.com/code360/problems/subarrays-with-xor-k_6826258?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include<bits/stdc++.h>
#include<vector>
using namespace std;
int subarraysWithSumK(vector < int > a, int b) {

    map<int,int> mpp;

    mpp[0] = 1; // storing 0 to the map first

    int xr = 0;

    int cnt = 0;

    for(int i =0;i<a.size();i++){

        xr = xr ^ a[i];

        int x = xr ^ b;

        cnt += mpp[x];// if x ele is present increase the cnt 

        mpp[xr]++;

 

    }

    return cnt;

 

}

