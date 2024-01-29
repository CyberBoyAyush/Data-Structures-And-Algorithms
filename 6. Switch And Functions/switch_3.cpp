#include<iostream>
using namespace std;

int main(){
    int n ;
    cin>>n;
    int type;
    cin>>type;

 
    switch(type){
        case 100 :  cout<<"there are "<<n/type<<" Notes of 100 in n:"<<n<<endl;  
        break;
        case 50 :  cout<<"there are "<<n/type<<" Notes of 50 in n:"<<n<<endl; 
        break; 
        case 20 :  cout<<"there are "<<n/type<<" Notes of 20 in n:"<<n<<endl; 
        break; 
        case 10 :  cout<<"there are "<<n/type<<" Notes of 10 in n:"<<n<<endl; 
        break; 
    }
}