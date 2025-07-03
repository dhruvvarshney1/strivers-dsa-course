/*
    Author: Dhruv Varshney
    Date - 2025/06/28
    Time - 13:06:11
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

class Solution {
public:
    vector<int> findOrder(int num, vector<vector<int>>& pre) {
        vvi adj(num);
        vi in(num, 0);
        for (const auto& p : pre) {
            int course = p[0];
            int prereq = p[1];
            adj[prereq].push_back(course); 
            in[course]++;         
        }
        queue<int> q;
        for(int i = 0; i < num; i++) {
            if(in[i] == 0) {
                q.push(i);
            }
        }

        vi topo;
        int course = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(int x : adj[node]) {
                in[x]--;
                if(in[x] == 0) {
                    q.push(x);
                }
            }
        }

        if(topo.size() != num) {
            return {};
        }
        return topo;
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
        vi a(n);
        for(int &x : a) cin >> x;
        Solution sol;
        
    }
    return 0;
}