#include<bits/stdc++.h>
using namespace std;
#define fo(i,n) for(int i = 0 ;i<n ;i++)

void Heapify(int * arr,int index,int n){
    int smallest = index;
    int leftchild = 2*index + 1;
    int rightchild = 2*index + 2;

    // comparing the values
    if(leftchild<n && arr[leftchild]<arr[smallest]){
        smallest = leftchild; // left is our new smallest
    }
    if(rightchild<n && arr[rightchild]<arr[smallest]){
        smallest = rightchild; // right is our new smallest
    }

    // now updating the val
    if(smallest != index){
        //changed 
        swap(arr[smallest],arr[index]);
        Heapify(arr,smallest,n);
    }

}

void buildMinHeap(int* arr,int n){
    // step down approach --> optimal O(N)
    for(int i = n/2-1;i>=0;i--){ // 
        Heapify(arr,i,n);
    }
}


// print func
void print(int * arr, int size){
    for(int i = 0;i<size;i++){
        cout<<arr[i]<<" ";
    } cout<<endl;
}
int main(){
    int arr[] = {1,3,45,56,4,3,23,55,23,11};
    buildMinHeap(arr,10);
    print(arr,10);
    return 0;
}