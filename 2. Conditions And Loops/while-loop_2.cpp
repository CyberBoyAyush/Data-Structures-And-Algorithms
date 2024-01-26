#include<iostream>
using namespace std;

int main(){
    int n,i,sum;
    cout<<"Enter n"<<endl;
    cin>>n;

    i = 1;
    sum = 0;
    
    while(i<=n){
        sum = sum+i;
        i++;
    }
    cout<<sum;
}