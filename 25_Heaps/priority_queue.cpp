#include<bits/stdc++.h>
using namespace std;
#define fo(i,n) for(int i = 0 ;i<n ;i++)

// create a func to print priority queue
void print(priority_queue<int> pq){
  while(!pq.empty()){
    cout<<pq.top()<<" ";
    pq.pop();
  }
  cout<<endl;
}

// create a func to find the sum of pq
int sum(priority_queue<int> pq){
  int sum = 0;
  while(!pq.empty()){
    sum += pq.top();
    pq.pop();
  }
  return sum;
}

int main(){
  // create a priority queue
  priority_queue<int> pq;
  pq.push(10);
  pq.push(15);
  pq.push(5);
  pq.push(20);
  print(pq);
  cout<<sum(pq);
  return 0;
}