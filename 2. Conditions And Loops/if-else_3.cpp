#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter Your Number"<<endl;
    cin>>n;

    if(n>0){
        cout<<"Your Number is +ve";
    }
    else{
        if(n<0){
            cout<<"Your number is -ve"<<endl;
            
        }
        else{
            cout<<"Your number is 0"<<endl;
        }
    }

    // int n;
    // n = cin.get();
    // cin>> n;
    // cout<<"Value of n:"<<n<<endl;

}