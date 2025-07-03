/*
    Author: Dhruv Varshney
    Date - 2025/07/02
    Time - 23:51:35
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
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();
        if(grid[0][0] != 0 || grid[n-1][n-1] != 0) {
            return -1;
        }

        int dx[] = {0, 0, 1, -1, 1, -1, 1, -1};
        int dy[] = {1, -1, 0, 0, 1, -1, -1, 1};

        queue<pair<int,int>> q;
        q.push({0, 0});
        grid[0][0] = 1;
        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            if(x == n-1 && y == n-1) {
                return grid[x][y];
            }
            for(int i = 0; i < 8; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if(nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 0) {
                    grid[nx][ny] = grid[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        return -1;
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