#include<iostream>
using namespace std;

void update(int *ptr){
    (*ptr)++;
}

int main(){
    int value = 5;
    int *ptr = &value;
    cout<< "Before " << value  <<endl;
    cout<< "Before " << *ptr <<endl;
    update(ptr);
    cout<< "After " << *ptr <<endl;
    cout<< "After " << value  <<endl;
    return 0;
}