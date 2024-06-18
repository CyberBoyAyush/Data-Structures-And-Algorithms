#include<iostream>
#include<climits>
using namespace std;

int maxRow(int arr[][3], int n, int m){
    int maxi = INT_MIN;
    int rowIndex = -1;;
    for(int row = 0; row<3;row++){
        int sum = 0;
        for(int col = 0; col<3; col++){
            sum += arr[row][col];
        }
        if(maxi<sum){
            maxi = sum;
            rowIndex = row;
        }
        
    }
    cout<<" mAx sum is "<< maxi<< endl;
    return rowIndex;
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

    cout<< maxRow(arr,3,3) <<endl;
    


}