// Two Sum
// https://www.naukri.com/code360/problems/reading_6845742?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
#include<vector>
#include<string>
#include<bits/stdc++.h>
using namespace std;

string read(int n, vector<int> book, int target)
{
    int left = 0, right = n-1;
    sort(book.begin(),book.end());

    while(left<right){
        int sum = book[left] + book[right];
        if(sum == target){
            return "YES";
        }
        else if(sum<target){
            left++;
        }
        else{
            right--;
        }
    }
    return "NO";
}
