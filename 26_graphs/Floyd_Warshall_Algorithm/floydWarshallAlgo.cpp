// Floyd Warshall Algorithm

#include<bits/stdc++.h>
using namespace std;
#define fo(i,n) for(int i = 0 ;i<n ;i++)

// TC : O(N^3) SC : O(N^2)
class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    int n = matrix.size(); // size of the matrix or nodes present
	    
	    // Converting all the -1 in matrix to INT_MAX for floyd algo
	    for(int i = 0; i<n ; i++){
	        for(int j = 0; j<n ; j++){
	            if(matrix[i][j] == -1){
	                matrix[i][j] = INT_MAX;
	            }
	        }
	    }
	    
	    // Applying Floyd Warshall ALgorithm
	    for(int via = 0 ; via<n ; via++){
	        // via is our intermediate node
	        for(int i = 0 ; i< n ; i++){
	            for(int j = 0 ; j< n ; j++){
	                // checking for edge case condt
	                if(matrix[i][via] == INT_MAX || matrix[via][j] == INT_MAX) continue;
	                
	                
	                matrix[i][j] = min(matrix[i][j] , matrix[i][via] + matrix[via][j]);
	            }
	        }
	    }
	    
	    // Now converting all remaning INT_MAX to -1 for final ans
	    for(int i = 0; i<n ; i++){
	        for(int j = 0; j<n ; j++){
	            if(matrix[i][j] == INT_MAX){
	                matrix[i][j] = -1;
	            }
	        }
	    }
	}
};