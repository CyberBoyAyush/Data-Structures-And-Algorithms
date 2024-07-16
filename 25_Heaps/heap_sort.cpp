// Heap sort
// TC - O(NlogN)
#include<bits/stdc++.h>
using namespace std;
#define fo(i,n) for(int i = 0 ;i<n ;i++)


void Heapify(int * arr,int index,int n){
    int largest = index;
    int leftchild = 2*index + 1;
    int rightchild = 2*index + 2;

    // comparing the values
    if(leftchild<n && arr[leftchild]>arr[largest]){
        largest = leftchild; // left is our new largest
    }
    if(rightchild<n && arr[rightchild]>arr[largest]){
        largest = rightchild; // right is our new largest
    }

    // now updating the val
    if(largest != index){
        //changed 
        swap(arr[largest],arr[index]);
        Heapify(arr,largest,n);
    }

}

void buildMaxHeap(int* arr,int n){
    // step down approach --> optimal O(N)
    for(int i = n/2-1;i>=0;i--){ // 
        Heapify(arr,i,n);
    }
}

void heapSort(int* arr, int n){
    for(int i = n-1;i>=0;i--){ // n-1 is our last el
        // swapping first and last el
        swap(arr[i],arr[0]);
        // (apply heapify upuntil size - last element = n-1 ) on el 0 -> bcz this we have to send to correct place
        Heapify(arr,0,i);
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
    buildMaxHeap(arr,10);
    print(arr,10);
    heapSort(arr,10); // our heap sorting func
    print(arr,10);
    return 0;
}