// https://www.naukri.com/code360/problems/count-digits_8416387?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

int countDigits(int n){
	int d,num,count=0;

    num=n;

    while(num>0){

        d=num%10;

        if (d!=0 && n % d == 0) {

            count++;

            }

            num /= 10;

    }

        return count;	
}