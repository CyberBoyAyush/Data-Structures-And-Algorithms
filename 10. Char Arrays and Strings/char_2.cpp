//length of char array

#include<iostream>
using namespace std;

int main(){
    char name[20];
    cout<<"Enter Your Name:"<<endl;

    cin>>name;
    int count = 0;
    for(int i = 0; name[i] != '\0' ;i++){
        count ++;
    }
    cout<<count<<endl;
}