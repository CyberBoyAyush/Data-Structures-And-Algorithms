// Find whether path exists
// GFG : https://practice.geeksforgeeks.org/problems/find-whether-path-exist/0

#include<bits/stdc++.h>
using namespace std;

// Approach 1 -> Using BFS Method
// Time Complexity : O(N^2)
class Solution
{
    public:
    int delRow[4] = {1,-1,0,0};
    int delCol[4] = {0,0,1,-1};
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        // BFS 
        queue<pair<int,int>> q;
        
        // Finding the source
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j< n ;j++){
                if(grid[i][j] == 1){
                    // Pushing source in queue
                    q.push({i,j});
                    // making in visityyed
                    grid[i][j] = 0;
                    
                    // edge case
                }
            }
        }
        
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(int i = 0 ; i< 4 ; i++){
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];
            
                
                // check condt
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n){
                    
                    if(grid[nrow][ncol] == 2) return true;
                    
                    if(grid[nrow][ncol] != 0){
                        q.push({nrow,ncol});
                        grid[nrow][ncol] == 0;
                    }
                }
            }
        }
        
        return false;
        
    }
};

// Approach 2 -> Using DFS Method
// Time Complexity : O(N^2)
// Space Complexity : O(N^2)
class Solution
{
    public:
    int delRow[4] = {1,-1,0,0};
    int delCol[4] = {0,0,1,-1};
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        // DFS
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j< n ;j++){
                if(grid[i][j] == 1){
                    // making in visityyed
                    grid[i][j] = 0;
                    if(dfs(grid,i,j,n)) return true;
                }
            }
        }
        
        return false;
        
    }
    
    bool dfs(vector<vector<int>>& grid,int row,int col,int n){
        if(grid[row][col] == 2) return true;
        
        for(int i = 0 ; i< 4 ; i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            
            // check condt
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n){
                if(grid[nrow][ncol] != 0){
                    grid[nrow][ncol] = 0;
                    if(dfs(grid,nrow,ncol,n)) return true;
                }
            }
        }
        
        return false;
    }
};