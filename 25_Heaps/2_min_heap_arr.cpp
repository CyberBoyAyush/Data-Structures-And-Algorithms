#include <bits/stdc++.h>
using namespace std;

class MinHeap {
    int* arr;
    int size; // elements that are currently present in heap
    int totalSize; // total elements that can be present

public:
    // constructor
    MinHeap(int n) {
        arr = new int[n];
        size = 0;
        totalSize = n;
    }

    // insertion func
    void insert(int x) {
        // heap is full
        if (size == totalSize) {
            cout << "Heap is full." << endl;
            return;
        }
        arr[size] = x;
        int index = size;
        size++;

        // compare it with its parent to check if it is present at the correct pos
        int parentPos = (index - 1) / 2;
        while (index > 0 && arr[index] < arr[parentPos]) {
            swap(arr[index], arr[parentPos]);
            index = parentPos;
            parentPos = (index - 1) / 2;
        }

        cout << arr[index] << " is inserted in the MinHeap." << endl;
    }

    // print func for printing the minheap
    void print() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // deletion in minheap
    // we always delete the min number from heap which is the root node
    void Delete() {
        // if heap empty
        if (size == 0) {
            cout << "heap underflow" << endl;
            return;
        }

        // swapping the largest to root node
        arr[0] = arr[size - 1];
        size--;

        if (size == 0) {
            // single element
            return;
        }

        // send the root to correct pos
        Heapify(0);
    }

    // Heapify func to send the swapped node to its correct place
    void Heapify(int index) {
        int smallest = index; // assuming index has the smallest element
        int left = index * 2 + 1; // child node location
        int right = index * 2 + 2; // child node location

        // checking position
        if (left < size && arr[left] < arr[smallest]) {
            smallest = left; // left is new smallest
        }
        if (right < size && arr[right] < arr[smallest]) {
            smallest = right; // right is our new smallest
        }

        // now we check if any operations are needed for swap
        if (smallest != index) {
            // means smallest has changed and we need to swap
            swap(arr[index], arr[smallest]);
            Heapify(smallest); // recursive call for final
        }
    }
};

int main() {
    MinHeap H1(6);
    H1.insert(4);
    H1.insert(20);
    H1.insert(180);
    H1.insert(100);
    H1.print();
    H1.Delete();
    H1.print();
    return 0;
}
