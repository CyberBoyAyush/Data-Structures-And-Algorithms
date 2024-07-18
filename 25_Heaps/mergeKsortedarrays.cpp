// merge k sorted arrays
// GFG
// https://www.geeksforgeeks.org/problems/merge-k-sorted-arrays/1
#include<bits/stdc++.h>
using namespace std;
#define fo(i,n) for(int i = 0 ;i<n ;i++)

class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        vector<pair<int,pair<int,int>>> temp;
        for(int i = 0; i<K;i++){
            temp.push_back(make_pair(arr[i][0] , make_pair(i,0)));
        }
        //min heap
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq(temp.begin(),temp.end());
        
        
        vector<int> ans; // final answer vector
        pair<int,pair<int,int>> element; // for retrival of top
        int i,j;
        while(!pq.empty()){
            element = pq.top();
            pq.pop();
            ans.push_back(element.first);
            i = element.second.first; // row 
            j = element.second.second; // col 
            
            if(j+1<K){ // checking index range
                pq.push(make_pair(arr[i][j+1] , make_pair(i,j+1)));
            } 
            
        }
        return ans;
        
    }
};
