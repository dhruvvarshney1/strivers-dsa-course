/*
    Author: Dhruv Varshney
    Date - 2025/06/27
    Time - 10:15:30
*/

#include <bits/stdc++.h>
using namespace std;

// #define int long long
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

class Solution {
private:
    vi dfs(int node, const vvi &adj, bool vis[], sti &st) {
        vis[node] = 1;
        for(auto it : adj[node]) {
            if(!vis[it]) {
                dfs(it, adj, vis, st);
            }
        }
        st.push(node);
    }
public:
    vi topoSort(vvi adj) {
        sti st;
        int m = adj.size();

        bool vis[m]= {0};

        for(int i = 0; i < m; i++) {
            if(!vis[i]) {
                dfs(i, adj, vis, st);
            }
        } 

        vi ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
    vi kahnAlgorithm(vvi adj) {

        int n = adj.size();
        vi res(n, 0);

        for(auto it : adj) {
            for(int x : it) {
                res[x]++;
            }
        }

        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(res[i] == 0) {
                q.push(i);
            }
        }

        vi topo;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(int x : adj[node]) {
                res[x]--;
                if(res[x] == 0) {
                    q.push(x);
                }
            }
        }

        if(topo.size() != n) {
            throw "Cycle in the graph";
        }
        else {
            return topo;
        }
    }
};

int main() {
    Solution sol;
    // Graph with 6 vertices (0 to 5)
    vvi adj(6);
    adj[2].push_back(3);
    adj[3].push_back(1);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[5].push_back(0);
    adj[5].push_back(2);
    // Expected order: 4, 5, 0, 2, 3, 1 (or other valid orders)
    try {
        vi topo = sol.kahnAlgorithm(adj);
        cout << "Topological Sort: ";
        for (int node : topo) {
            cout << node << " ";
        }
        cout << endl;
    } catch (const std::runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }

    cout << "\n--- DFS Based Sort ---" << endl;
    vi topo_dfs = sol.topoSort(adj);
    cout << "Topological Sort: ";
    for (int node : topo_dfs) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}

