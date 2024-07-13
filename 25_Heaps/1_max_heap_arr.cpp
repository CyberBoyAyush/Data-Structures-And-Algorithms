#include<bits/stdc++.h>
using namespace std;
#define fo(i,n) for(int i = 0 ;i<n ;i++)

class MaxHeap{
    int * arr;
    int size; // elements that are curently present in heap
    int totalSize; // total el that can be present

    public:
    // constructor
    MaxHeap(int n){
        arr = new int[n];
        size = 0;
        totalSize = n;
    }

    // insertion func
    void insert(int x){
        // heap is full
        if(size == totalSize){
            cout<<"Heap is full."<<endl;
            return;
        }
        arr[size] = x;
        int index = size;
        size++;

        // compare it with its parent to chekc if it is present at the correct pos

        int parentPos = (index-1) / 2;
        while(index>0 && arr[index] > arr[parentPos]){
            swap(arr[index],arr[parentPos]);
            index = parentPos;
        }

        cout << arr[index] <<" is inserted in the MaxHeap."<<endl;
    }

    // print func for printing the maxheap
    void print(){
        for(int i = 0;i<size;i++){
            cout<<arr[i]<<" ";
        } cout<<endl;
    }

    // deletion in maxheap
    // we always delted the max num form heap which is root node
    void Delete(){
        // if heap empty
        if(size == 0){
            cout<<"heap underflow"<<endl;
        }

        // swapping the smallest to root node
        arr[0] = arr[size-1];
        size--;

        if(size == 0){
            // single el
            return;
        }

        // send the root to correct pos
        Heapify(0);
    }

    // Heapify func to send the swapped node to its correct place
    void Heapify(int index){
        int largest = index; // assuming index has the largest el
        int left = index * 2 + 1; // child node location
        int right = index * 2 + 2; // child node location

        // checking pos
        if(left<size && arr[left] > arr[largest]){
            largest = left; // left is new largest.
        }
        if(right<size && arr[right] > arr[largest]){
            largest = right; // right is our new largest.
        }

        // now we check if any operations are need for swap
        if(largest != index){
            // means largest has changed and we need to swap
            arr[index] = arr[largest];
            Heapify(largest); // recursive call for final
        }
    }
};

int main(){
  MaxHeap H1(6);
  H1.insert(4);
  H1.insert(20);
  H1.insert(180);
  H1.insert(100);
  H1.print();
  H1.Delete();
  H1.print();
  return 0;
}