//  Implement Upper Bound
// https://www.naukri.com/code360/problems/implement-upper-bound_8165383?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
#include<vector>
using namespace std;
int upperBound(vector<int> &arr, int x, int n){
	int s = 0;
	int e = n-1;
	int m = s + (e-s)/2;
	int ans = n;

	while(s<=e){
		if(arr[m]>x){
			ans = m;
			e = m-1;
		}
		else{
			s = m+1;
		}
		m = s + (e-s)/2;
	}	
	return ans;
}