// Bubble SOrt Using Recursion

#include<iostream>
using namespace std;

void sortArray(int *arr, int n){
    if(n==0||n==1){
        return ;
    }

    //solve one case
    for(int i =0; i<n-1;i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }

    //recursive call
    sortArray(arr,n-1);
}

int main(){
    int arr[5] = {2,3,6,4,1};
    int n = 5;

    sortArray(arr,n);

    for(int i = 0; i<n;i++){
        cout<<arr[i]<<" ";
    }
}