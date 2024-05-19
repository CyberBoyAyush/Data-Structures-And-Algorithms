// Find Minimum in Rotated Sorted Array
// https://www.naukri.com/code360/problems/rotated-array_1093219?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include<vector>
#include<climits>
using namespace std;
int findMin(vector<int>& arr)
{
	int low = 0;
	int high = arr.size()-1;
	int ans = INT_MAX;

	while(low<=high){
		int mid = (low+high)/2;

		if(arr[low]<=arr[mid]){
			ans = min(ans,arr[low]);
			low = mid +1;
		}
		else{
			ans = min(ans,arr[mid]);
			high = mid -1;
		}
	}
	return ans;
}