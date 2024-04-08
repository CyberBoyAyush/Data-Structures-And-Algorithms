// Subarray Sum Equals K
// https://leetcode.com/problems/subarray-sum-equals-k/
#include<vector>
using namespace std;
#include<unordered_map>
class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
    unordered_map<int,int> m;
    m[0] = 1;
    int sum = 0, count = 0;
    for(int i =0 ; i < arr.size();i++){
        sum += arr[i];
        count += m[sum-k];
        m[sum] += 1;
    }
    return count;
}

};