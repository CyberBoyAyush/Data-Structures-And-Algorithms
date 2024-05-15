#include<iostream>
using namespace std;

void printWord(int n, string *arr){
    if(n==0){
        return;
    }
    int digit = n%10;
    n = n/10;

    printWord(n,arr);
    cout<<arr[digit]<<" ";
}
int main(){
    string arr[10] = {"Zero","One","Two","Three","Four","Five","Six","seven","Eight","nine"};
    int n;
    cin>>n;

    printWord(n,arr);
}