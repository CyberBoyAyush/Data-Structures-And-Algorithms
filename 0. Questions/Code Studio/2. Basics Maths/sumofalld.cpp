// https://www.naukri.com/code360/problems/sum-of-all-divisors_8360720?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM
// Sum of all divisors

int sumOfAllDivisors(int n){

    // Write your code here.    

    int sum = 0;

    for(int i = 1; i <= n; i++){

        sum += (n / i) * i;

    }

    return sum;

}