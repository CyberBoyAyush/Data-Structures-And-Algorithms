//Aggressive Cows
// https://www.naukri.com/code360/problems/aggressive-cows_1082559?interviewProblemRedirection=true&search=cows&attempt_status=COMPLETED
#include<vector>
#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;
bool canWePlace(vector<int> &stalls, int mid, int k){
    int cntCows = 1; // It will always we one
    int last = stalls[0]; // this is the position of the last cow that we will use as the reference
    for(int i = 0; i<stalls.size();i++){
        if(stalls[i] - last >= mid){
            cntCows++;
            last = stalls[i];
        }
       
    }
    return cntCows>=k;
    
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(),stalls.end());
    int n = stalls.size();
    int low = 0;
    int high = stalls[n-1] - stalls[0]; // bca the range will be in 1 ---> max-min (although we can keep it as 10^9 also)
    int ans = -1;
    while(low<=high){
        int mid = (low + high) / 2;
        if(canWePlace(stalls,mid, k)){
            ans = mid;
            low = mid + 1; // bcz we need max
        }
        else{
            high = mid - 1;
        }
    }
    return high;
}