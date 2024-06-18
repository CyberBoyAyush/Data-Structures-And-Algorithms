#include<iostream>
using namespace std;

int fact(int a){
    int factorial= 1;
    for(int i = 1; i<=a; i++){
        factorial = factorial * i; 
    }
    return factorial;
}

int nCr(int n, int r){
    int num = fact(n);
    int denom = fact(r) * fact(n-r);

    return num/denom;
}

int main(){
    int n,r;
    cin>>n>>r;

    cout<<"Answer is "<< nCr(n,r)<<endl;

}