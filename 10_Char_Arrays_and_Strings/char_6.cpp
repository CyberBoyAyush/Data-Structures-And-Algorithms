#include<iostream>
using namespace std;

char getMaxOccuringChar(string str)
    {
        // Your code here
        int map[26]={0};
        
        for(int i=0;i<str.length();i++){
            map[str[i]-'a']++;
        }
        
        int freq=0;
        char ans;
        for(int i=0;i<26;i++){
            if(freq<map[i]){
                freq=map[i];
                ans=i+'a';
            }
        }
        return ans;
        
    }

int main(){
    string name;
    cin>>name;

    cout<<getMaxOccuringChar(name);
}
