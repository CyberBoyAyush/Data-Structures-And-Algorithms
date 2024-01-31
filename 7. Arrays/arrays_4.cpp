#include<iostream>
using namespace std;

int main(){
    int arr[5];

    int sizeArray = sizeof(arr)/sizeof(int);
    // To find the size of arrays we use size of function and divide it with size of integer to find how many locations are there in array.
    cout<<sizeArray;
}