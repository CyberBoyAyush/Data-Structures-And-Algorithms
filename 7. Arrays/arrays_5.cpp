// Max and min Number from an array.

#include<iostream>
#include <climits>
// #include <climits>
using namespace std;

int getMax(int arr[], int size){
    int max = INT_MIN;
    for(int i = 0; i<size;i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }
    return max;
}

int getMin(int arr[], int size){
    int min = INT_MAX;
    for(int i = 0; i<size;i++){
        if(arr[i]>min){
            min = arr[i];
        }
    }
    return min;
}


int main(){
    
    int size;
    cin>>size;

    int arr[100];

    for(int i = 1;i<=size;i++){
        cin>>arr[i];
    }

    cout<<"Max Value is "<< getMax(arr,size)<<endl;
    cout<<"Min Value is "<< getMin(arr,size)<<endl;
}