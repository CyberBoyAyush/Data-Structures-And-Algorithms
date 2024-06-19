// Print all the elements of queue
#include<bits/stdc++.h>
using namespace std;

int main(){
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    // Brute force [O(n)]
    vector<int> ans;
    while(!q.empty()){
        cout<<q.front()<<"  ";
        ans.push_back(q.front());
        q.pop();
    }
    for(auto i : ans){
        q.push(i);
    }

    cout<<endl;
    cout<<"Optimal Approach Sol"<<endl;
    // Optimal Approach - [O(1)]
    // We Rotate in Queue

    int n = q.size();
    while(n--){
        cout<<q.front()<<"  ";
        q.push(q.front());
        q.pop();
    }
    return 0;
}