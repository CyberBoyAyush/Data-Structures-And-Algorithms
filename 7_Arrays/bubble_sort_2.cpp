#include<iostream>
using namespace std;

// we optimized this code to check if the arr is sortedso it will give us the best time complexity of O(n) rather then the usual case O(n^2).

int swapArrray(int arr[],int n){
    for(int i = 1; i<n; i++){
        // running loop from 1 to n
        bool swapped = false;
        for(int j = 0; j<n-1; j++){
            //running loop from n-i
            if(arr[j]>arr[j+1]){
                swapped = true;
                swap(arr[j],arr[j+1]);
            }
                if(swapped = false){
                    break;
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