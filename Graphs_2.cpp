/*
    Author: Dhruv Varshney
    Date - 2025/06/20
    Time - 00:12:26
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
// UTILS
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef set<int> si;
typedef unordered_set<int> usi;
typedef map<int, int> mii;
typedef unordered_map<int, int> umii;
typedef stack<int> sti;
typedef deque<int> dqi;

const int mod = 7 + 1e9;

class graph {
    private:
    void dfs(int node,vvi &adj, vi &vis, vi &res) {
        vis[node] = 1;
        res.push_back(node);

        for(auto i : adj[node]) {
            if(!vis[i]) {
                dfs(i, adj, vis, res);
            }
        }
    }

    public:
    vi graphDFS(vvi adj) {
        int n = adj.size();
        vi vis(n, 0);
        vi res;

        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                dfs(i, adj, vis, res);
            }
        }

        return res;
    }
};

// ## How to Use the Graph Class
signed main() {
    // Example of a disconnected graph with 7 nodes (0-6)
    // Component 1: 0-1-2-3
    // Component 2: 4-5
    // Component 3: 6 (isolated node)
    int n = 7;
    vvi adj(n);

    // Edges for component 1
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(2);

    // Edges for component 2
    adj[4].push_back(5);
    adj[5].push_back(4);

    // Node 6 has no edges

    // --- Using the class ---
    graph g;
    vi dfs_traversal = g.graphDFS(adj);

    for (int node : dfs_traversal) {
        cout << node << " ";
    }
    cout << endl;
    // Expected Output: 0 1 2 3 4 5 6 (order within components may vary)

    return 0;
}
