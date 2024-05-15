#include<iostream>
using namespace std;

int main(){
    // creating array
    int n,m;
    cin>>n;
    cin>>m;

    int **arr = new int * [n];

    for(int i = 0; i<n; i++){
        arr[i] = new int [m];
    }

    // taking input
    for(int i = 0; i<n; i++){
        for(int j= 0; j<m ; j++){
            cin>>arr[i][j];
        }
    }

    // taking output
    for(int i = 0; i<n; i++){
        for(int j= 0; j<m ; j++){
            cout<<arr[i][j]<<" ";
        } cout<<endl;
    }

    return 0;
}