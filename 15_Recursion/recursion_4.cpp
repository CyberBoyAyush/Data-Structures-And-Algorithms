#include<iostream>
using namespace std;

void reachedHome(int src, int des){
    if(src==des){
        cout<<"Reached Home!!"<<endl;
        return ;
    }

    src++;
    
    reachedHome(src,des);
}

int main(){
    int src = 1;
    int des = 10;

    reachedHome(src,des);
}