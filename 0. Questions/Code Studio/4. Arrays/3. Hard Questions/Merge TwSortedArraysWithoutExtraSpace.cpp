#include<vector>
#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
// Merge Two Sorted Arrays Without Extra Space
//https://www.naukri.com/code360/problems/merge-two-sorted-arrays-without-extra-space_6898839?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b){
	// Write your code here.
	int i = a.size() -1;
	int j = 0;

	while(a[i] > b[j]){
		swap(a[i], b[j]);
		i--;
		j++;
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
}