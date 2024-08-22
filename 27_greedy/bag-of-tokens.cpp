// Bag of Tokens
// Leetcode : https://leetcode.com/problems/bag-of-tokens/

// Approach -> Greedy
// Tc - O(nlogn)
// Sc - O(1)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();

        int score = 0; // intially score is 0;
        int maxScore = 0;

        sort(tokens.begin(),tokens.end());

        int i = 0, j = n-1;
        while(i<=j){
            // score badhao
            if(power >= tokens[i]){
                power-=tokens[i]; // power kam ki
                score++; // score badha diya
                i++;

                maxScore = max(maxScore,score);
            }
            // score gathao power badhao
            else if(score >= 1){
                score--; // score kam kara
                power += tokens[j]; // power badha li
                j--;
            }
            else{
                return maxScore;
            }
        }
        return maxScore;
    }
};