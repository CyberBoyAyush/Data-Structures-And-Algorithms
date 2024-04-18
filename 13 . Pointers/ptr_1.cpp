#include <iostream>
using namespace std;

int main()
{
    // int num = 5;
    // int *ptr = &num;

    // // printing value of num using pointer
    // cout << *ptr << endl;

    // // printing address of num using pointer
    // cout << ptr << endl;

    // // copying a pointer
    // int *q = ptr;
    // cout<< "q " << *q << "ptr " << *ptr <<endl;
    float f = 10.5;
float p = 2.5;
float* ptr = &f;
(*ptr)++;
*ptr = p;
cout << *ptr << " " << f << " " << p;
}