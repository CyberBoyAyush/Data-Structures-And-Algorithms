#include<iostream>
using namespace std;

bool linearsearch(int *arr,int size,int k){
    if(size==0){
        return false;
    }
    if(arr[0]==k){
        return true;
    }
    
    bool rem = linearsearch(arr+1,size-1,k);
    return rem;
}

int main(){
    int arr[5] = {3,1,2,5,8};
    int size = 5;
    int k = 2;
    bool ans = linearsearch(arr,size,k);

    if(ans){
        cout<<"Present"<<endl;
    }
    else{
        cout<<"Not Present"<<endl;
    }
}