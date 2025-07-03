/*
    Author: Dhruv Varshney
    Date - 2025/06/30
    Time - 10:33:46
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

class Solution
{
private:
    void dfs(int node, const vector<vector<pair<int, int>>> &adj, vector<bool> &vis, sti &st)
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it.first])
            {
                dfs(it.first, adj, vis, st);
            }
        }
        st.push(node);
    }
public:
    vi shortestPath(vvi edge)
    {
        int n = edge.size();
        vvi adj(n);
        for (int i = 0; i < n; i++)
        {
            auto p = edge[i];
            adj[p[0]].push_back(p[1]);
            adj[p[1]].push_back(p[0]);
        }

        vi dist(n, INT_MAX);
        queue<pair<int, int>> q;

        q.push({0, 0});
        while (!q.empty())
        {
            int node = q.front().first, x = q.front().second;
            q.pop();
            for (int i : adj[node])
            {
                dist[i] = min(dist[i], x + 1);
                if (x + 1 == dist[i])
                {
                    q.push({dist[i], x + 1});
                }
            }
        }
    }
    vi shortDagPath(int src, vvi edge)
    {
        int n = edge.size();
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < n; i++)
        {
            auto p = edge[i];
            adj[p[0]].push_back({p[1], p[2]});
        }

        sti st;
        vector<bool> vis(n);

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                dfs(i, adj, vis, st);
            }
        }

        vi dist(n, INT_MAX);
        dist[src] = 0;

        while (!st.empty())
        {
            int node = st.top();
            st.pop();
            for (auto it : adj[node])
            {
                dist[it.first] = min(dist[it.first], dist[node] +it.second);
            }
        }

        return dist;
    }
};

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _t = 1;
    // cin >> _t;
    while (_t--)
    {
        int n;
        cin >> n;
        vi a(n);
        for (int &x : a)
            cin >> x;
        Solution sol;
        vvi edges2 = {{0, 1, 2}, {1, 2, 3}, {0, 2, 6}, {2, 3, 1}};
        vi result2 = sol.shortDagPath(0, edges2);

        for (int i = 0; i < result2.size(); i++)
        {
            cout << result2[i] << ' ';
        }
    }
    return 0;
}