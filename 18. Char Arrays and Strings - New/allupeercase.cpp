#include<bits/stdc++.h>
using namespace std;
void upperCase(char *ch){
    int n = strlen(ch);

    for(int i = 0; i<n; i++){
        if(ch[i]>='a' && ch[i]<='z'){
            ch[i] = ch[i] - 'a' + 'A';
        }
    }

    cout<<ch<<endl;
}
int main(){
    char ch[100];

    cin.getline(ch,100);

    upperCase(ch);

    return 0;
}