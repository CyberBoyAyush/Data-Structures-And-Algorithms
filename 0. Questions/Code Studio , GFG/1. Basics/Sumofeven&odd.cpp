// https://www.naukri.com/code360/problems/sum-of-even-odd_624650?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include<iostream>
using namespace std;

int main() {
	// Write your code here
	int n,i,sumEven,sumOdd;
	cin>>n;

while(n!=0){
	i = n%10;
	if(i%2==0){
		sumEven = sumEven + i;
	}
	else{
		sumOdd = sumOdd + i;
	}
	n= n/10;
}
cout<<sumEven<<" "<<sumOdd;
}
