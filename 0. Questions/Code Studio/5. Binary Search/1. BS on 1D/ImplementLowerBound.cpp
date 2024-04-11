// Implement Lower Bound
// https://www.naukri.com/code360/problems/lower-bound_8165382?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include<vector>
using namespace std;
int lowerBound(vector<int> arr, int n, int x) {
	int s = 0;
	int e = n-1;
	int m = s+(e-s)/2;
	int ans = -1;

	if(arr[0]>=x){

        return 0;

    }

    if(arr[n-1]<x){

        return n;

    }

	while(s<=e){
		if(arr[m]>=x){
			ans = m;
			e = m-1;
		}
		else{
			s = m+1;
		}
		m = s+(e-s)/2;
	}
	return ans;
}
