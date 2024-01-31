#include<iostream>
using namespace std;

//Printing and arrays using function
void printArray(int arr[], int size){
    for(int i = 0;i<=size;i++){
        cout<<arr[i]<<endl;
    }
    cout<<"Printing Done"<<endl;
}

int main(){
    int arr[5] = {0};
    printArray(arr,4);

}