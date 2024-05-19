// https://www.naukri.com/code360/problems/check-prime_624674?utm_source=striver&utm_medium=website&utm_campaign=codestudio_a_zcourse

#include<iostream>
using namespace std;

int main() {
	 int n;

    cin>>n;

    bool isPrime=true;

    for(int i=2;i*i<=n;i++){

        if(n%i==0) {

            isPrime=false;

            break;

        }

    } 

    if(isPrime) cout<<"true"<<endl;

    else cout<<"false"<<endl;


	
}
