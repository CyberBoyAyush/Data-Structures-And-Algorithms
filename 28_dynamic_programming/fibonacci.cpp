// Fibonacci series using dynamic programming
// Time Complexity: O(n)
// Space Complexity: O(n)

#include<bits/stdc++.h>
using namespace std;

// mermization
int fib(int n , vector<int> &dp){
    if(n==0 || n == 1){
        return n;
    }
    if(dp[n]!=-1){
        return dp[n];
    }

    dp[n] = fib(n-1,dp) + fib(n-2,dp);
}

// tabulation
int fib2(int n){
    vector<int> dp(n+1,-1);
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

// Optimized space complexity
int fib3(int n ){
    int prev2 = 0, prev = 1;

    for(int i = 2 ; i<=n ; i++){
        int curr = prev2 + prev;
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    cout<<fib(n,dp);
    cout<<fib2(n);
    cout<<fib3(n);
    return 0;
}