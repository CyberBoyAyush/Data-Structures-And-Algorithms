#include<iostream>
using namespace std;

int swapArrray(int arr[],int n){
    for(int i = 0; i<n-1; i++){
        int minIndex = i;
        for(int j = i+1; j<n; j++){
            if(arr[j]<arr[minIndex]){
                minIndex = j;
            }
        }
        
    swap(arr[minIndex],arr[i]);
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