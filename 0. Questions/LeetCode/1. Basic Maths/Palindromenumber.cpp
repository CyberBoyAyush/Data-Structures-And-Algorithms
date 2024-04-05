// Palindrome https://leetcode.com/problems/palindrome-number/
#include<climits>
class Solution {
public:
    bool isPalindrome(int n) {
      int rev = 0;
        int dup = n;
	while(n>0){
		int last = n%10;
        if((rev > INT_MAX/10) || (rev < INT_MIN/10)){
                return 0;
            }
		rev = (rev*10) + last;
		n = n/10;
	}
    if(dup==rev){
        return true;
    }
    else{
        return false;
    }  
    }
};