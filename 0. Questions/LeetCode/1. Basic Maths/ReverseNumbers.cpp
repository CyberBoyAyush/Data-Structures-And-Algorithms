// https://leetcode.com/problems/reverse-integer/
#include<climits>
class Solution {
public:
    int reverse(int n) {
        int rev = 0;
        while(n!=0){
		int last = n%10;
        if((rev > INT_MAX/10) || (rev < INT_MIN/10)){
                return 0;
            }

		rev = (rev*10) + last;
		n = n/10;
	}
        return rev;
    }
};