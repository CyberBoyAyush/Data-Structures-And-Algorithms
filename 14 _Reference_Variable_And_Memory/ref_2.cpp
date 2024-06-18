#include<iostream>
using namespace std;

void update1(int n){ // we are creating a copy of our main variable n here so it will not affect our original variable (PASS BY VALUE)
    n++;
}

void update2(int& n){ // Here we are passing by reference (address of our variable) in the function so it is nto a copy.
    n++;
}

int main(){
    int n = 5;
    cout<< "Before " << n <<endl;
    update1(n);
    cout<< "After " << n <<endl;
    cout<< "Before " << n <<endl;
    update2(n);
    cout<< "After " << n <<endl;
}