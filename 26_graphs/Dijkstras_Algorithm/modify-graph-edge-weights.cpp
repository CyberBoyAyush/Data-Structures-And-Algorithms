// Modify Graph Edge Weights
// Leetcode : https://leetcode.com/problems/path-with-maximum-minimum-value/

#include<bits/stdc++.h>
using namespace std;

// Approach 1: Dijkstra's Algorithm
// Time Complexity: O(ElogV)
// Space Complexity: O(E+V)

class Solution {
public:
    typedef long long ll;
    const int LARGE_VALUE = 2e9;
    typedef pair<long, long> P;

    ll DijkstraAlgo(vector<vector<int>>& edges, int n, int src, int dest) {
        //make the graph excluing -1 et edges
        unordered_map<ll, vector<pair<ll, ll>>> adj; //u -> (v, wt)

        for(vector<int>& edge : edges) {
            if(edge[2] != -1) {
                int u  = edge[0];
                int v  = edge[1];
                int wt = edge[2];

                adj[u].push_back({v, wt});
                adj[v].push_back({u, wt});
            }
        }

        priority_queue<P, vector<P>, greater<P>> pq;
        vector<ll> result(n, INT_MAX); //result[i] = shortest path distance of src to ith node
        vector<bool> visited(n, false);

        result[src] = 0; //src to src distance is 0
        pq.push({0, src});

        while(!pq.empty()) {
            ll currDist = pq.top().first;
            ll currNode = pq.top().second;
            pq.pop();

            if(visited[currNode] == true) {
                continue;
            }
            visited[currNode] = true;

            for(auto P : adj[currNode]) {
                auto nbr = P.first;
                auto wt = P.second;
                if(result[nbr] > currDist + wt) {
                    result[nbr] = currDist + wt;
                    pq.push({result[nbr], nbr});
                }
            }
        }

        return result[dest];
    }

    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        ll currShortestDist = DijkstraAlgo(edges, n, source, destination);

        if(currShortestDist < target) {
            return {};
        }

        bool matchedTarget = (currShortestDist == target);

        for(vector<int>& edge : edges) {
            if(edge[2] == -1) {

                edge[2] = (matchedTarget == true) ? LARGE_VALUE : 1; //assign lowest number i.e. 1

                if(matchedTarget != true) {
                    ll newShortestDist = DijkstraAlgo(edges, n, source, destination);

                    if(newShortestDist <= target) {
                        matchedTarget = true;
                        edge[2] += (target - newShortestDist);
                    }
                }
            }
        }

        if(matchedTarget == false) {
            return {};
        }
        return edges;
    }
};

// Approach 2: Union Find
// Time Complexity: O(ElogE)
// Space Complexity: O(E+V)

class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int u) {
        if(parent[u] == u) {
            return u;
        }
        return parent[u] = find(parent[u]);
    }

    void unionSet(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if(pu != pv) {
            if(rank[pu] < rank[pv]) {
                swap(pu, pv);
            }
            parent[pv] = pu;
            rank[pu] += rank[pv];
        }
    }

    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        vector<vector<int>> result;

        sort(edges.begin(), edges.end(), [&](vector<int>& a, vector<int>& b) {
            return a[2] < b[2];
        });

        parent.resize(n);
        rank.resize(n);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }

        for(vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            unionSet(u, v);

            if(find(source) == find(destination)) {
                if(wt == -1) {
                    edge[2] = target;
                }
                result.push_back(edge);
            }
        }

        return result;
    }
};