#include<bits/stdc++.h>
using namespace std;
void insertSpace(char * ch){
    for(int i =0;i<strlen(ch);i++){
        if(ch[i] == '@'){
            ch[i] = ' ';
        }
    }

    cout<<ch<<endl;
}
int main(){
    char ch[100];
    cin.getline(ch,100);

    insertSpace(ch);
return 0;
}