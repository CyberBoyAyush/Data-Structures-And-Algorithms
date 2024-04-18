// Koko Eating Bananas
// https://leetcode.com/problems/koko-eating-bananas/
// https://leetcode.com/problems/koko-eating-bananas/discuss/5036998/C%2B%2B-Code-Binary-Search-Easy-Explanation

#include<vector>
#include<climits>
#include<math.h>
using namespace std;
class Solution {
private:
    int findMax(vector<int>& piles){
        int maxi = INT_MIN;
        for(int i = 0 ; i<piles.size();i++){
            maxi = max(piles[i],maxi);
        }
        return maxi;
    }
    
    double totalH(vector<int>& piles, int h){
        double totalHrs = 0;
        for(int i = 0 ; i<piles.size(); i++){
            totalHrs += ceil((double)(piles[i]) / (double)(h));
        }
        return totalHrs;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = findMax(piles);
        int ans = INT_MIN; // for storing mid until the lowest
        while(low<=high){
            int mid = (low + high) / 2;
            double hours = totalH(piles,mid);
            if(hours<=h){
                ans = mid;
                high = mid - 1; // bcz we need minimum we go to the left part of array.
            }
            else{
                low = mid + 1; // we will go to right part of array.
            }
        }
        return ans;
    }
};