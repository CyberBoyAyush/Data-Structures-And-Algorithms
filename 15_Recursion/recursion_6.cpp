#include<iostream>
using namespace std;

bool isSorted(int *arr, int size){
    if(size==0 || size==1){
        return true;
    }
    if(arr[0]>arr[1]){
        return false;
    }
    else{
        bool ans = isSorted(arr+1,size-1);
        return ans;
    }
}

int main(){
    int arr[5] = {1,5,3,4,5};
    int size = 5;

    bool ans = isSorted(arr,size);

    if(ans){
        cout<< "Sorted"<<endl;
    }
    else{
        cout<<"Not Sorted."<<endl;
    }
}