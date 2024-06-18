#include<iostream>
using namespace std;

int sumArray(int *arr, int size){
    if(size==0){
        return 0;
    }
    if(size==1){
        return arr[0];
    }
    else{
        int rem = sumArray(arr+1,size-1);
        int sum = arr[0] + rem;
        return sum;
    }
}

int main(){
    int arr[5] = {1,5,3,4,5};
    int size = 5;


    cout<<" Sum is "<< sumArray(arr,size);


}