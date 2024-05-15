#include<iostream>
using namespace std;

inline int getMax(int &a,int&b){
    return (a>b) ? a:b;
}

int main(){
    int a = 2;
    int b = 3;

    int ans = getMax(a,b);
    cout<< ans<<endl;

    a += 3;
    b += 1;
    
    
    ans = getMax(a,b);
    cout<< ans<<endl;

}