// Remove Duplicates from Sorted Array
// https://www.naukri.com/code360/problems/remove-duplicates-from-sorted-array_1102307?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
#include<vector>
using namespace std;
int removeDuplicates(vector<int> &arr, int n) {
	int c = 1;
	for(int i = 0;i<n-1;i++){
		if(arr[i]!=arr[i+1]){
			c++;
		}
	}
	return c;

}