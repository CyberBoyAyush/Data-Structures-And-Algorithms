//length of char array
#include<bits/stdc++.h>
using namespace std;

int findLength(char *ch,int size){
    int len = 0;
    for(int i = 0 ; i<size;i++){
        if(ch[i] == '\0'){
            break;
        }
        else{
            len++;
        }
    }
    return len;
}

int main(){
    char ch[100];

    cin>>ch;

    // building func
    int len = findLength(ch,100);

    cout<<"len of str " << len <<endl;

    // prebuilt func
    cout<< "length from prebuild func : " << strlen(ch)<<endl;
    
 return 0;
}