#include<iostream>
using namespace std;

void printSum(int arr[][3], int n, int m){
    for(int row = 0; row<3;row++){
        int sum = 0;
        for(int col = 0; col<3; col++){
            sum += arr[row][col];
        }
        cout<<sum<<" ";
    }
}

int main(){
    // initializing 2d arr
    int arr[3][3];

    //Taking input
    for(int row = 0; row<3;row++){
        for(int col = 0; col<3; col++){
            cin>>arr[row][col];
        }
    }

    // output
    for(int row = 0; row<3;row++){
        for(int col = 0; col<3; col++){
            cout<<arr[row][col]<<" ";
        }
        cout<<endl;
    }

    
    printSum(arr,3,3);


}