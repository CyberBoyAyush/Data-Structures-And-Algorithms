#include<iostream>
using namespace std;

int getSum(int *arr, int n){
    // cout<< sizeof(arr)<<endl; // it is passing pointer not the complete array
    int sum = 0;
    for (int i = 0 ;i<n;i++){
        sum += arr[i];
    }
    return sum;
}

int main(){
    int arr[5] = {1,2,3,4,5};

    cout<<getSum(arr,5)<<endl;
    cout<<getSum(arr + 2,3)<<endl;

    return 0;
}