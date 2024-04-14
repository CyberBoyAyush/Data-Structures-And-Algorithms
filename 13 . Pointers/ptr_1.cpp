#include <iostream>
using namespace std;

int main()
{
    int num = 5;
    int *ptr = &num;

    // printing value of num using pointer
    cout << *ptr << endl;

    // printing address of num using pointer
    cout << ptr << endl;

    // copying a pointer
    int *q = ptr;
    cout<< "q " << *q << "ptr " << *ptr <<endl;
}