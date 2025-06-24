/*
    Author: Dhruv Varshney
    Date - 2025/06/19
    Time - 22:29:14
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
    public:
    vi graphBFS(vvi adj) {
        int n = adj.size();

        int vis[n] = {0};
        vis[0] = 1;

        queue<int> q;
        q.push(0);
        vi bfs;

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            bfs.push_back(node);

            for(auto it : adj[node]) {
                if(!vis[it]) {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        return bfs;
    }
};

signed main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 1. Define a sample graph using an adjacency list
    // This graph has 6 vertices (0 to 5)
    int V = 6;
    vvi adj(V);

    // Add edges to the graph
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(0);
    adj[1].push_back(3);
    adj[1].push_back(4);
    adj[2].push_back(0);
    adj[3].push_back(1);
    adj[4].push_back(1);
    adj[4].push_back(5);
    adj[5].push_back(4);
    
    // Example Graph:
    // 0 -- 1 -- 3
    // |    |
    // 2    4 -- 5

    // 2. Create an instance of the graph class
    graph g;

    // 3. Call the BFS function to get the traversal
    vi bfs_traversal = g.graphBFS(adj);

    // 4. Print the resulting BFS traversal
    for(int i = 0; i < bfs_traversal.size(); ++i) {
        cout << bfs_traversal[i] << ' ';
    }
    cout << endl;

    return 0;
}
