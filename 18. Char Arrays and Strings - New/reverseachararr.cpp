// reverse a char arr
#include<bits/stdc++.h>
using namespace std;

void reverse(char *ch){
    int start = 0;
    int end = strlen(ch) - 1;
    while(start<end){
        swap(ch[start],ch[end]);
        start++;
        end--;
    }

    cout<<ch<<endl;
}
int main(){
    char ch[100];

    cin>>ch;

    reverse(ch);
 return 0;
}