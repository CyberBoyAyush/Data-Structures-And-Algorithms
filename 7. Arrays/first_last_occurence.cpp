#include<iostream>
using namespace std;

int firstOccurence(int arr[], int size,int key){
    int start = 0;
    int end = size - 1;
    int mid = start + (end-start)/2;
    int ans = -1;
    while(start<=end){
        if(key==arr[mid]){
            ans = mid;
            end = mid-1;
        }
        else if(key>arr[mid]){
            start = mid + 1;
        }
        else if(key<arr[mid]){
            end = mid - 1;
        }
        mid = start + (end-start)/2;
    }
    return ans;
}
int lastOccurence(int arr[], int size,int key){
    int start = 0;
    int end = size - 1;
    int mid = start + (end-start)/2;
    int ans = -1;
    while(start<=end){
        if(key==arr[mid]){
            ans = mid;
            start = mid+1;
        }
        else if(key>arr[mid]){
            start = mid + 1;
        }
        else if(key<arr[mid]){
            end = mid - 1;
        }
        mid = start + (end-start)/2;
    }
    return ans;
}

int main(){
    int even[7] = {1,2,3,3,3,3,5};
    cout<<"index is "<<firstOccurence(even,7,3)<<endl;
    cout<<"index is "<<lastOccurence(even,7,3)<<endl;
    return 0;
}