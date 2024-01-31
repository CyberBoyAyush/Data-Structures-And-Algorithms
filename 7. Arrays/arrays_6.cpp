#include<iostream>
using namespace std;


int arrSum(int arr[], int n){
    int sum = 0;
    for(int i = 1;i<=n;i++){
        sum = sum + arr[i];
    }
    return sum;
}

int main(){
    // int size;
    // cin>>size;
    int num[5];
    for(int i = 0; i<5; i++){
        cin>>num[i];
    }
    cout<<"sum is "<<arrSum(num,5);
}