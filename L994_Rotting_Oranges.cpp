/*
    Author: Dhruv Varshney
    Date - 2025/06/21
    Time - 12:47:36
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
    int orangesRotting(vector<vector<int>>& a) {
        if(a.empty()) return 0;
        
        int m = a.size(), n = a[0].size(), total_oranges = 0, total_time = 0, count_rotten = 0;
        
        queue<pair<int, int>> q;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n ; j++) {
                if(a[i][j] != 0) {
                    total_oranges++;
                }
                if(a[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        while(!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if(nx >= 0 && nx < m && ny >= 0 && ny < n && a[nx][ny] == 1) {
                    a[nx][ny] = 2;
                    count_rotten++;
                    q.push({nx, ny});
                }
            }
            
        }
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
        cout << sol.orangesRotting(a) << '\n';
        
    }
    return 0;
}