// https://www.naukri.com/code360/problems/nth-fibonacci-number_74156?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include<bits/stdc++.h>
using namespace std;

int fib(int n){
        if(n == 1){
                return 1;
        }
        else if(n==2){
                return 1;
        }
        else{
                return fib(n-1) + fib(n-2);
        }
}
int main()
{
    int n;
    cin>>n;

    cout<<fib(n);
}