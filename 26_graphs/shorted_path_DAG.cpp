// Shortest path in Directed Acyclic Graph

#include <bits/stdc++.h>
using namespace std;
#define fo(i, n) for (int i = 0; i < n; i++)

// dfs code for topo sort
void dfs(int node, vector<pair<int, int>> adj[], stack<int> &st, vector<bool> &vis)
{
    vis[node] = 1; // mark it visited

    // traverse in neighbours
    for (auto &v : adj[node])
    {
        if (!vis[v.first])
        {
            dfs(v.first, adj, st, vis);
        }
    }

    // pushing value in track during backtrack
    st.push(node);
}
vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
{
    // create adj list
    vector<pair<int, int>> adj[N];
    // pushing values in adj
    for (int i = 0; i < M; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];

        adj[u].push_back({v, weight});
    }

    // we find the topological sort for the graph
    // we use dfs in it (can use bfs -> kahn's algo also)

    stack<int> st;
    vector<bool> vis(N, 0);
    dfs(0, adj, st, vis);

    // dist vector
    vector<int> dist(N, INT_MAX);
    dist[0] = 0; // updating source dist which is 0 acc to ques

    // empty stack
    while (!st.empty())
    {
        int node = st.top();
        st.pop();

        // check in neighbours
        for (auto &v : adj[node])
        {
            int neighbour = v.first;
            int weight = v.second; // bcz both are stored in pair

            // finding dist
            dist[neighbour] = min(dist[neighbour], weight + dist[node]);
        }
    }

    // edge case if non conneted graphs
    for (int i = 0; i < N; i++)
    {
        if (dist[i] == INT_MAX)
        {
            dist[i] = -1;
        }
    }

    return dist;
}

int main()
{
    int N = 6;
    int M = 6;
    vector<vector<int>> edges = {{0, 1, 2}, {0, 2, 3}, {1, 3, 4}, {2, 4, 5}, {2, 5, 6}, {3, 5, 1}};
    vector<int> res = shortestPath(N, M, edges);
    for (int i = 0; i < N; i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}