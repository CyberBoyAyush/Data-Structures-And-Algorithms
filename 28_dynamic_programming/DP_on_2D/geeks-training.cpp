// Geeks Training
// https://www.geeksforgeeks.org/problems/geeks-training/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=geeks-training

// Appraoch 1: Recursion
// Time Complexity: O(2^n)
// Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int f(int day, int last, vector<vector<int>> &arr)
    {
        if (day == 0)
        {
            // base case
            int maxi = 0;
            for (int task = 0; task <= 2; task++)
            {
                if (task != last)
                {
                    maxi = max(maxi, arr[0][task]);
                }
            }
            return maxi;
        }

        int maxi = 0;

        for (int task = 0; task < 3; task++)
        {
            if (task != last)
            {
                int points = arr[day][task] + f(day - 1, task, arr);
                maxi = max(maxi, points);
            }
        }

        return maxi;
    }
    int maximumPoints(vector<vector<int>> &arr, int n)
    {
        return f(n - 1, 3, arr);
    }
};

// Approach 2: Recursion + Memoization
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution
{
public:
    int f(int day, int last, vector<vector<int>> &arr, vector<vector<int>> &dp)
    {
        if (day == 0)
        {
            // base case
            int maxi = 0;
            for (int task = 0; task <= 2; task++)
            {
                if (task != last)
                {
                    maxi = max(maxi, arr[0][task]);
                }
            }
            return maxi;
        }

        if (dp[day][last] != -1)
        {
            return dp[day][last];
        }

        int maxi = 0;

        for (int task = 0; task < 3; task++)
        {
            if (task != last)
            {
                int points = arr[day][task] + f(day - 1, task, arr, dp);
                maxi = max(maxi, points);
            }
        }

        return dp[day][last] = maxi;
    }
    int maximumPoints(vector<vector<int>> &arr, int n)
    {
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return f(n - 1, 3, arr, dp);
    }
};

// Approach 3: Tabulation
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution
{
public:
    int maximumPoints(vector<vector<int>> &arr, int n)
    {
        vector<vector<int>> dp(n, vector<int>(4, 0));

        dp[0][0] = max(arr[0][1], arr[0][2]);
        dp[0][1] = max(arr[0][0], arr[0][2]);
        dp[0][2] = max(arr[0][0], arr[0][1]);
        dp[0][3] = max({arr[0][0], arr[0][1], arr[0][2]});

        for (int day = 1; day < n; day++)
        {
            for (int last = 0; last < 4; last++)
            {
                for (int task = 0; task < 3; task++)
                {
                    if (task != last)
                    {
                        int points = arr[day][task] + dp[day - 1][task];
                        dp[day][last] = max(dp[day][last], points);
                    }
                }
            }
        }
        return dp[n - 1][3];
    }
};

// Approach 4: Optimized Tabulation
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution
{
public:
    int maximumPoints(vector<vector<int>> &arr, int n)
    {
        // Initialize a vector to store the maximum points for the previous day's activities
        vector<int> prev(4, 0);

        // Initialize the DP table for the first day (day 0)
        prev[0] = max(arr[0][1], arr[0][2]);
        prev[1] = max(arr[0][0], arr[0][2]);
        prev[2] = max(arr[0][0], arr[0][1]);
        prev[3] = max(arr[0][0], max(arr[0][1], arr[0][2]));

        // Iterate through the days starting from day 1
        for (int day = 1; day < n; day++)
        {
            // Create a temporary vector to store the maximum points for the current day's activities
            vector<int> temp(4, 0);
            for (int last = 0; last < 4; last++)
            {
                temp[last] = 0;
                // Iterate through the tasks for the current day
                for (int task = 0; task <= 2; task++)
                {
                    if (task != last)
                    {
                        // Calculate the points for the current activity and add it to the
                        // maximum points obtained on the previous day (stored in prev)
                        temp[last] = max(temp[last], arr[day][task] + prev[task]);
                    }
                }
            }
            // Update prev with the maximum points for the current day
            prev = temp;
        }

        // The maximum points for the last day with any activity can be found in prev[3]
        return prev[3];
    }
};