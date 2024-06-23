#include<bits/stdc++.h>
using namespace std;
// Linear Search
// TC - O(N*M)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        for(int i = 0; i<m; i++){
            for(int j = 0 ; j<n ;j++){
                if(matrix[i][j] == target){
                    return true;
                }
            }
        }
        return false;
    }
};

// Binary Search
// TC - O(log(n*m))
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int start = 0;
        int end = n*m - 1;

        while(start<=end){
            int mid = start + (end-start) / 2;

            // Converting 1D Indexes to 2d indexes for BS
            int row = mid/n;
            int col = mid%n;

            if(matrix[row][col] == target){
                return true;
            }
            else if(matrix[row][col] > target){
                end = mid -1;
            }
            else{
                start = mid + 1;
            }
        }
        return false;
    }
};