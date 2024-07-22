#include<bits/stdc++.h>
using namespace std;
#define fo(i,n) for(int i = 0 ;i<n ;i++)


// this is the code for creating a graph using adjacency matrix in directed weighted graph
int main(){
    // for weighted directed graphs
    int vertex, edges;
    cin>>vertex>>edges;

    // int matrix for weighted graphs
    vector<vector<int>> AdjMat(vertex,vector<int>(vertex,0));

    // input from users -> edge
    int u,v,weight;
        for(int i = 0;i<edges;i++){
            cin>>u>>v;
            AdjMat[u][v] = weight;
        }

        //printing the matrix
        for(int i = 0;i<vertex;i++){
            for(int j = 0;j<vertex;j++){
                cout<<AdjMat[i][j]<<" ";
            } cout<<endl;
        }
  return 0;
}