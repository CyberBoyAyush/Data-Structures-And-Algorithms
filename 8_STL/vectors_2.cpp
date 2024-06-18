#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v;
    vector<int> v1;
    vector<int> v2;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    for(auto it = v.begin(); it != v.end() ;it++){
        cout<< *it<<endl;
    }

    cout<<endl;

    for(auto it:v){
        cout<<it<<endl;
    } cout<<endl;

    // erase() – It is used to remove elements from a container from the specified position or range.
    v.erase(v.begin());
    for(auto it:v){
        cout<<it<<endl;
    } cout<<endl;

    // insert() – It inserts new elements before the element at the specified position
    v.insert(v.begin(),10);
    for(auto it:v){
        cout<<it<<endl;
    } cout<<endl;

    // inserts at the beginning
    v.emplace(v.begin(), 5);

    // swap() – It is used to swap the contents of one vector with another vector of same type. Sizes may differ.
    v1.swap(v2);

    // clear() - erases the entire vector
    v1.clear();
}
