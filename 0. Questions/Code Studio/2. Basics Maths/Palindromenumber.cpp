// https://www.naukri.com/code360/problems/palindrome-number_624662?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

bool palindrome(int n)
{
	int rev = 0;
    int dup = n;
	while(n>0){
		int last = n%10;
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