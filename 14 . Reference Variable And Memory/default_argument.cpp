#include<iostream>
using namespace std;

void printArr(int *arr, int n , int start = 0){
    for(int i = start ; i<n;i++){
        cout<<arr[i]<<endl;
    }
}

int main(){
    int arr[5] = {1,2,3,4,5};

    printArr(arr,5);
    
    cout<<endl;
    
    printArr(arr,5,2);
}