// Koko Eating Bananas
// https://www.naukri.com/code360/problems/minimum-rate-to-eat-bananas_7449064?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
#include<vector>
#include <bits/stdc++.h>
using namespace std;
int findMax(vector<int> &piles) {
  int maxi = INT_MIN;
  for (int i = 0; i < piles.size(); i++) {
    maxi = max(maxi, piles[i]);
  }
  return maxi;
}

double totalH(vector<int> &piles, int h) {
  double totalHrs = 0;
  for (int i = 0; i < piles.size(); i++) {
    totalHrs += ceil((double)(piles[i]) / (double)(h));
  }
  return totalHrs;
}

int minimumRateToEatBananas(vector<int> piles, int h) {
  int low = 1, high = findMax(piles);
  int ans = 1; // for storing mid until the lowest
  while (low <= high) {
    int mid = (low + high) / 2;
    double hours = totalH(piles, mid);
    if (hours <= h) {
      ans = mid;
      high = mid - 1; // bcz we need minimum we go to the left part of array.
    } else {
      low = mid + 1; // we will go to right part of array.
    }
  }
  return ans;
}