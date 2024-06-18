// Rat IN A Maze
// https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
// Rat In A Maze
//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    private:
    
    bool isSafe(int newx,int newy,int n,vector<vector<int>> &m,vector<vector<int>> &visited){
        if((newx>=0 && newx<n) && (newy>=0 && newy<n) && m[newx][newy] == 1 && visited[newx][newy] == 0){
            return true;
        }
        else{
            return false;
        }
    }
    void solve(vector<vector<int>>& m, int n, vector<string>& ans, string path, int x, int y, vector<vector<int>>& visited)
{
        // You have reached x and y here
        if(x==n-1 && y == n-1){
            ans.push_back(path);
            return;
        }
        
        visited[x][y] = 1;
        
        // 4 coices D,L,R,U
                // Move Down
        int newx = x + 1;
        int newy = y;
        if (isSafe(newx, newy, n, m, visited)) {
            path.push_back('D');
            solve(m, n, ans, path, newx, newy, visited);
            path.pop_back();
        }

        // Move Left
        newx = x;
        newy = y - 1;
        if (isSafe(newx, newy, n, m, visited)) {
            path.push_back('L');
            solve(m, n, ans, path, newx, newy, visited);
            path.pop_back();
        }

        // Move Right
        newx = x;
        newy = y + 1;
        if (isSafe(newx, newy, n, m, visited)) {
            path.push_back('R');
            solve(m, n, ans, path, newx, newy, visited);
            path.pop_back();
        }

        // Move Up
        newx = x - 1;
        newy = y;
        if (isSafe(newx, newy, n, m, visited)) {
            path.push_back('U');
            solve(m, n, ans, path, newx, newy, visited);
            path.pop_back();
        }
        
        visited[x][y] = 0;
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        
        if(m[0][0]==0){
            return ans;
        }
        
        int x = 0;
        int y = 0;
        
        vector<vector<int>> visited(n, vector<int>(n, 0));

        
        // initializing array with 0
        for(int i = 0; i<n;i++){
            for(int j = 0; j<n;j++){
                visited[i][j] = 0;
            }
        }
        
        string path = "";
        
        solve(m,n,ans,path,x,y,visited);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends