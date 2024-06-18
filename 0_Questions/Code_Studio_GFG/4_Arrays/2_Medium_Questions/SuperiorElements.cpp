// Superior Elements
// https://www.naukri.com/code360/problems/superior-elements_6783446?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

#include<vector>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
vector<int> superiorElements(vector<int> &a) {
  vector<int> ans;
  int maxi = 0;
  int n = a.size();
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] > maxi) {
      ans.push_back(a[i]);
    }
    maxi = max(maxi, a[i]);
    // maxi = a[i]; // because we need maximum of maxi and a[i] so we use the
    // above line not this one
  }
  sort(ans.begin(), ans.end());
  return ans;
}