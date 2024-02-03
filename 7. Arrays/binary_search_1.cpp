#include<iostream>
using namespace std;

int binarySearch(int arr[],int size,int key){
    int start = 0;
    int end = size-1;
    // int mid = (start+end)/2;
    int mid = start + (end-start)/2;
    
    while(start<=end){
        if(arr[mid] == key){
            return mid;
        }

        // if key is greater then mid go to right side
        if(key>arr[mid]){
            start = mid+1;
        }
        // if key is greater then mid go to left side
        else{
            end = mid -1;
        }
        // now from above our start or mid is updated we also have to update mid
        // mid = (start+end)/2;
        mid = start + (end-start)/2;
    }
    return -1;
}

int main(){
    int even[6] = {2,3,5,6,8,12};
    int odd[5] = {2,3,5,16,18};

    int evenArr = binarySearch(even,6,12);
    int oddArr = binarySearch(odd,5,16 );

    cout<< "index is "<< evenArr<<endl;
    cout<< "index is "<< oddArr<<endl;
}