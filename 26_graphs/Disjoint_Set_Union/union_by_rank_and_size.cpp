// Union by rank

#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> rank,parent,size;

    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i = 0 ; i < n ; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }


    int findParent(int u){
        if(u==parent[u]){
            return u;
        }

        return parent[u] = findParent(parent[u]);
    }

    void UnionByRank(int u , int v){
        int pu = findParent(u);
        int pv = findParent(v);

        if(rank[pu] > rank[pv]){
            parent[pv] = pu;
        }

        else if(rank[pu] < rank[pv]){
            parent[pu] = pv;
        }

        else{
            parent[pv] = pu;
            rank[pu]++;
        }
    }

    void UnionBySize(int u , int v){
        int pu = findParent(u);
        int pv = findParent(v);

        if(size[pu] > size[pv]){
            parent[pv] = pu;
            size[pu] += size[pv];
        }

        else{
            parent[pu] = pv;
            size[pv] += size[pu];
        }
    }
};

int main(){
    DisjointSet ds(5);
    ds.UnionByRank(1,2);
    ds.UnionByRank(4,2);
    ds.UnionByRank(3,1);

    for(int i = 0 ; i < 5 ; i++){
        cout<<ds.findParent(i)<<" ";
    }
    return 0;
}
