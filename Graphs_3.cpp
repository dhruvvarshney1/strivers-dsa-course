/*
    Author: Dhruv Varshney
    Date - 2025/06/22
    Time - 21:52:53
*/

#include <bits/stdc++.h>
using namespace std;


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
    bool isDetectBFS(int src, vector<vector<int>> &adj, bool vis[]) {
        vis[src] = 1;

        queue<pair<int, int>> q;
        q.push({-1, src});

        while(!q.empty()) { 

            int bfr = q.front().first, node = q.front().second;
            q.pop();

            for(auto it : adj[node]) {
                if(!vis[it]) {
                    vis[it] = 1;
                    q.push({node, it});
                }
                else if(it != bfr) {
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs(int src, int parent,vector<vector<int>> &adj, bool vis[]) {
        vis[src] = 1;
        for(auto it : adj[src]) {
            if(!vis[it]) {
                if(dfs(it, src, adj, vis) == true) {
                    return true;
                }
            }
            else if(it != src) {
                return true;
            }
        }
        return false;
    } 
public:
    bool isCycleBFS(int n, vector<vector<int>> adj) {
        bool vis[n] = {false};

        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                if(isDetectBFS(i, adj, vis)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool isCycleDFS(int n, vector<vector<int>> adj) {
        bool vis[n] = {false};

        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                if(dfs(i, -1, adj , vis)) {
                    return true;
                }
            }
        }
        return false;
    }
};
