/*
    Author: Dhruv Varshney
    Date - 2025/06/25
    Time - 15:54:01
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
    private:
    void dfs(vector<vector<char>>& b,vector<vector<bool>> &vis, int x, int y) {
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if(!vis[nx][ny] && b[nx][ny] == 'O') {
                vis[x][y] = 1;
                b[x][y] = 'X';
                dfs(b, vis, nx, ny);
            }
        }
    }
public:
    void solve(vector<vector<char>>& b) {
        int m = b.size(), n = b[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        for(int i = 0; i < m ; i++) {
            for(int j = 0; j < n; j++) {
                if(!vis[i][j] && b[i][j] == 'O') {
                    vis[i][j] = 1;
                    b[i][j] = 'X';
                    dfs(b, vis, i, j);
                }
            }
        }
    }
};