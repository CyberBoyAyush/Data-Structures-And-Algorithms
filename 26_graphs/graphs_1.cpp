#include<bits/stdc++.h>
using namespace std;
#define fo(i,n) for(int i = 0 ;i<n ;i++)


// this is the code for creating a graph using adjacency matrix in undirected unweighted graph
int main(){
    // for unwaighted undirected graphs
    int vertex, edges;
    cin>>vertex>>edges;

    // bool matrix for unwaited graphs
    vector<vector<bool>> AdjMat(vertex,vector<bool>(vertex,0));

    // input from users
    int u,v;
        for(int i = 0;i<edges;i++){
            cin>>u>>v;
            AdjMat[u][v] = 1;
            AdjMat[v][u] = 1;
        }

        //printing the matrix
        for(int i = 0;i<vertex;i++){
            for(int j = 0;j<vertex;j++){
                cout<<AdjMat[i][j]<<" ";
            } cout<<endl;
        }
  return 0;
}