#include <iostream>
using namespace std;

int main()
{
    
    int arr[10] = {2,3,4,5}; // initializing th array.

    // to get the address of first element of array
    cout<<"address of first element " << arr <<endl;
    cout<<"address of first element " << &arr[0] <<endl;

    // playing with pointer
    cout<< *arr << endl;
    cout<< *arr + 1 << endl;
    cout<< *(arr + 1) << endl;

    // to access the arr using index (both are same)
    cout<<"---"<<endl;
    cout<< arr[1] <<endl;
    cout<< *(arr + 1)<<endl;
    // crazy stuff
    int i = 3;
    cout<< "------"<<endl;
    cout<< i[arr] <<endl;

    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    // size of array
    cout<< sizeof(arr) << endl;
    cout<< sizeof(*arr) << endl;
    cout<< sizeof(&arr[0]) << endl;
    cout<<" <--> " << endl;
    int * p = &arr[0];
    cout<< sizeof(&arr[0]) << endl;
    cout<< sizeof(p) << endl;
    cout<< sizeof(&p) << endl;

    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;

    // address 
    cout<<" <--> "<< endl;
    cout<<&arr[0]<<endl;
    cout<<&p<<endl;


}