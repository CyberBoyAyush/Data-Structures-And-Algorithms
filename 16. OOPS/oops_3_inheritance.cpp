#include<bits/stdc++.h>
using namespace std;

class Human{
   public:
   int age;
   int weight;
   int height;
};

class Male: public Human{
    public:
    string name;
};

int main(){
    Male ayush;
    cout<<ayush.age<<endl;
    cout<<ayush.height<<endl;
    cout<<ayush.name<<endl;
    cout<<ayush.weight<<endl;

}