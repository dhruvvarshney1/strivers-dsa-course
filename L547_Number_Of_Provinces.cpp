/*
    Author: Dhruv Varshney
    Date - 2025/06/21
    Time - 00:00:25
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
    void _dfs_(int it, vvi adj, vector<bool> &vis, vi &res) {
        vis[it] = 1;
        res.push_back(it);
        for(int i : adj[it]) {
            _dfs_(i, adj, vis, res);
        }
    }
    public:
    vi graphDFS(vvi adj) {
        vi res;
        int n = adj.size();
        vector<bool> vis(n, false);

        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                _dfs_(i, adj, vis, res);
            } 
        }
    }

    vi graphBFS(vvi adj) {
        vi res;
        int n = adj.size();
        vector<bool> vis(n, false);

        queue<int> q;
        q.push(0);

        vis[0] = true;

        while(!q.empty()) {
            int tem = q.front();
            res.push_back(tem);
            q.push(tem);
            q.pop();

            for(int i : adj[tem]) {
                q.push(i);
            }
        }

        return res;
    }
};

class Solution {
    private:
    void dfs(int k, const vector<vector<int>> isCon, vector<bool> &vis) {
        vis[k] = 1;

        for(int j = 0; j < isCon[k].size(); j++) {
            if(isCon[k][j] == 1 && !vis[j]) {
                dfs(j, isCon, vis);
            }
        }
    }
    public:
    int findCircleNum(vector<vector<int>>& isCon) {

        int n = isCon.size();
        vector<bool> vis(n, false);

        int c=0;
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                c++;
                dfs(i, isCon, vis);
            }
        }

        return c;
    } 
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _t = 1;
    //cin >> _t;
    while (_t--) {
        int n;
        cin >> n;
        vvi a(n, vi(n));
        for(auto &x : a) {
            for(int &y : x) {
                cin >> y;
            }
        }

        Solution sol;
        cout << sol.findCircleNum(a) << '\n';
    }
    return 0;
}