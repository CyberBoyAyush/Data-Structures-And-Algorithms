// https://www.naukri.com/code360/problems/check-armstrong_589?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <bits/stdc++.h>

bool checkArmstrong(int n){

    //Write your code here

    int count=0,p=n;

    while(n!=0)

    {

         n=n/10;

         count++;

    }

  

   int sum=0,k=p;

   

    while(k!=0)

    {

        int p=k%10;

        sum=sum + pow(p,count);

        k=k/10;

    }

 

    if(sum==p) return true;

    else return false;

 

}