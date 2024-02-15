#include<iostream>
using namespace std;

int swapArrray(int arr[],int n){
     for(int i = 1 ; i<n; i++){
        int temp = arr[i];
        int j = i-1;
        for(; j>=0; j--){
            if(arr[j]>temp){
                arr[j+1] = arr[j];
            }
            else{
                break;
            }
        }
        arr[j+1] = temp;
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