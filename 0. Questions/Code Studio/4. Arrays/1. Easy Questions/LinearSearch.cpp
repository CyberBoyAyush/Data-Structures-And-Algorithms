// Linear Search
// https://www.naukri.com/code360/problems/linear-search_6922070?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include<vector>
using namespace std;
int linearSearch(int n, int num, vector<int> &arr)
{
    for(int i = 0; i<n;i++){
        if(num == arr[i]){
            return i;

        }
    }
    return -1;
}