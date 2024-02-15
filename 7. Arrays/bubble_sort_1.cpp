#include<iostream>
using namespace std;

int swapArrray(int arr[],int n){
    for(int i = 1; i<n; i++){
        // running loop from 1 to n
        for(int j = 0; j<n-1; j++){
            //running loop from n-i
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

int printArray(int arr[], int n){
    for(int i = 0; i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n] = {64,25,12,22,11};

    swapArrray(arr,n);
    cout<<printArray(arr,n);
    
}