#include<iostream>
using namespace std;

int main(){
    char ch[6] = "abcde";
    cout<<ch<<endl;
    char *c = &ch[0];
    char temp = 'z';
    char *cc = &temp;

    cout<<c<<endl;
    cout<<*c<<endl;
    cout<<cc<<endl;

    return 0;
}