// Different ways to add parentheses
// LeetCode : https://leetcode.com/problems/different-ways-to-add-parentheses/

#include <bits/stdc++.h>
using namespace std;

// Approach 1 : Recursion
// Time Complexity : O(2^n)
// Space Complexity : O(n)

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int>result;

        // iterating in expression
        for(int i = 0 ; i < expression.length(); i++){
            if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*'){
                vector<int> left_res = diffWaysToCompute(expression.substr(0,i));
                vector<int> right_res = diffWaysToCompute(expression.substr(i+1));

                //now we calcualte every possibility
                for(auto &x:left_res){
                    for(auto &y:right_res){
                        if(expression[i] == '+'){
                            result.push_back(x+y);
                        }
                        else if(expression[i] == '*'){
                            result.push_back(x*y);
                        }
                        else{
                            result.push_back(x-y);
                        }
                    }
                }
            }

        }
        
        // if there is no operator
        if(result.empty()){
            result.push_back(stoi(expression));
        } 

        return result;
    }
};


// Approach 2 : Recursion + Memoization
// Time Complexity : O(n^3)
// Space Complexity : O(n^3) + O(n) for recursive stack

class Solution {
public:
    unordered_map<string, vector<int>> memo;    
    vector<int> diffWaysToCompute(string expression) {
        vector<int>result;

        // memo call
        if(memo.find(expression) != memo.end()){
            return memo[expression];
        }

        // iterating in expression
        for(int i = 0 ; i < expression.length(); i++){
            if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*'){
                vector<int> left_res = diffWaysToCompute(expression.substr(0,i));
                vector<int> right_res = diffWaysToCompute(expression.substr(i+1));

                //now we calcualte every possibility
                for(auto &x:left_res){
                    for(auto &y:right_res){
                        if(expression[i] == '+'){
                            result.push_back(x+y);
                        }
                        else if(expression[i] == '*'){
                            result.push_back(x*y);
                        }
                        else{
                            result.push_back(x-y);
                        }
                    }
                }
            }

        }
        
        // if there is no operator
        if(result.empty()){
            result.push_back(stoi(expression));
        } 

        return memo[expression] = result;
    }
};

