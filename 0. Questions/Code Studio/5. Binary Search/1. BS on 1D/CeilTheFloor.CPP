// Ceil The Floor
// https://www.naukri.com/code360/problems/ceiling-in-a-sorted-array_1825401?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include<vector>
using namespace std;
int floorSearch(vector<int> & arr, int x, int n){
	int low = 0, high = n - 1;
	int ans = -1;

	while (low <= high) {
		int mid = (low + high) / 2;
		// maybe an answer
		if (arr[mid] <= x) {
			ans = arr[mid];
			//look for smaller index on the left
			low = mid + 1;
		}
		else {
			high = mid - 1; // look on the right
		}
	}
	return ans;
}
int ceilSearch(vector<int> & arr, int x, int n){
	int low = 0, high = n - 1;
	int ans = -1;

	while (low <= high) {
		int mid = (low + high) / 2;
		// maybe an answer
		if (arr[mid] >= x) {
			ans = arr[mid];
			//look for smaller index on the left
			high = mid - 1;
		}
		else {
			low = mid + 1; // look on the right
		}
	}
	return ans;
}
pair<int, int> getFloorAndCeil(vector<int> &arr, int n, int x) {
    pair<int , int> p;

    p.first = floorSearch(arr,  x,  n);

    p.second = ceilSearch(arr,  x,  n);
	return p;
}