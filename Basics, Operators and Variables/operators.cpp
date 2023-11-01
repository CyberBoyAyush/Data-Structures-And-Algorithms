#include<iostream>
using namespace std;

int main(){
    // Arithmetic operators
    int a = 2/5;
    cout << a << endl;

    float b = 2.0/5.0;
    cout << b << endl;

    int x = 4;
    int y = 6;

    cout << x+y << endl;
    cout << x-y << endl;
    cout << x*y << endl;
    cout << x/y << endl;
    cout << endl;
    // Relational Opertators
    int t = 3;
    int f = 4;
    bool first = (t==f);
    cout <<first<<endl;
    bool second = (t>f);
    cout <<second<<endl;
    bool third = (t<f);
    cout <<third<<endl;
    bool fourth = (t!=f);
    cout <<fourth<<endl;
}