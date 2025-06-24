/*
    Author: Dhruv Varshney
    Date - 2025/05/28
    Time - 16:16:08
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
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(), s.end());
        sort(g.begin(), g.end());

        int i = 0, j = 0;
        while(i < g.size() && j < s.size()) {
            if(g[i] <= s[j]) {
                i++;
            }
            j++;
        }
        
        return i;
    } 
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _t = 1;
    //cin >> _t;
    while (_t--) {
        int n, m;
        cin >> n >> m;
        vi a(n), b(m);
        for(int &x : a) cin >> x;
        for(int &y : b) cin >> y;
        Solution sol;
        cout << sol.findContentChildren(a, b) <<'\n';
    }
    return 0;
}