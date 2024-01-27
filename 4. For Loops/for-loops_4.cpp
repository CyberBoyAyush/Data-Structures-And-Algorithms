#include<iostream>
using namespace std;

int main(){ 
    int n;
    cin>>n;
    bool isPrime = 1;
    for(int i = 2; i<=n-1; i++){
        if(n%i==0){
            cout<<"This is not a prime number"<<endl;
            isPrime = 0;
            break;
        }
    }
    if(isPrime==1){
        cout<<"this is a prime no"<<endl;
    }
}