#include<iostream>
using namespace std;

bool binarysearch(int *arr, int s, int e,int key){
    if(s>e){
        return false;
    }
    int mid = (s+e)/2;
    if(arr[mid]==key){
        return true;
    }
    

    if(arr[mid]<key){
        return binarysearch(arr,mid+1,e,key);
    }
    else{
        return binarysearch(arr,s,mid-1,key);
    }
}

int main(){
    int arr[7] = {2,4,6,8,10,12,14};
    int size = 7;
    int s = 0;
    int e = size-1;
    int key = 10;

    bool ans = binarysearch(arr,s,e,key);

    if(ans){
        cout<<"Present"<<endl;
    }
    else{
        cout<<"Not Present"<<endl;
    }
}