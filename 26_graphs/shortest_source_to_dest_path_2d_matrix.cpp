// Shortest Path from source to destination in 2D Matrix
// GFG : https://practice.geeksforgeeks.org/problems/shortest-source-to-destination-path3544/1

#include<bits/stdc++.h>
using namespace std;
#define fo(i,n) for(int i = 0 ;i<n ;i++)

// Approach 1 - Using BFS Method
class Solution {
  public:
    int delRow[4] = {1,-1,0,0};
    int delCol[4] = {0,0,1,-1};
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // Edge cases
        if(X == 0 && Y == 0)    return 0; // source is the dest
        if(A[0][0]==0)  return -1; //no path exists
        
        // Queue for bfs traversal
        queue<pair<int,pair<int,int>>> q; // {row,{col,distance}}
        
        vector<vector<int>> visited(N , vector<int>(M,0)); 
        
        q.push({0,{0,0}});
        
        visited[0][0] = 1;
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second.first;
            int steps = q.front().second.second;
            q.pop();
            
            // Checking the neighbours -> L,R,U,D
            for(int i = 0 ; i<4 ; i++){
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];
                
                // Condt check
                if(nrow>=0 && nrow < N && ncol >= 0 && ncol < M
                && A[nrow][ncol] == 1 && !visited[nrow][ncol]){
                    
                    // If we reached our dest
                    if(nrow == X and ncol == Y){
                        return steps + 1;
                    }
                    
                    visited[nrow][ncol] = 1;
                    q.push({nrow , {ncol,steps+1}});
                }
            }
            
        }
        
        return -1;
    }
};

// Approach 2 - Using BFS Method with Better Space Complexity Without Visited Array
class Solution {
  public:
    int delRow[4] = {1,-1,0,0};
    int delCol[4] = {0,0,1,-1};
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // Edge cases
        if(X == 0 && Y == 0)    return 0; // source is the dest
        if(A[0][0]==0)  return -1; //no path exists
        
        // Queue for bfs traversal
        queue<pair<int,pair<int,int>>> q; // {row,{col,distance}}
        
        q.push({0,{0,0}});
        
        A[0][0] = 0; // marking it visited
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second.first;
            int steps = q.front().second.second;
            q.pop();
            
            // Checking the neighbours -> L,R,U,D
            for(int i = 0 ; i<4 ; i++){
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];
                
                // Condt check
                if(nrow>=0 && nrow < N && ncol >= 0 && ncol < M
                && A[nrow][ncol] == 1){
                    
                    // If we reached our dest
                    if(nrow == X and ncol == Y){
                        return steps + 1;
                    }
                    
                    A[nrow][ncol] = 0; // marking it visited
                    q.push({nrow , {ncol,steps+1}});
                }
            }
            
        }
        
        return -1;
    }
};