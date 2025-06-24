/*
    Author: Dhruv Varshney
    Date - 2025/06/06
    Time - 08:52:56
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
    string longestCommonPrefix(vector<string> &s) {
        string pre;
        if(s.empty()) return pre;

        int n = s.size();
        int min_len = INT_MAX;
        for(int i = 0; i < n ; i++) {
            min_len = min(min_len, (int)s[i].length());
        }

        for(int i = 0; i < min_len ; i++) {
            char ch = s[0][i];
            for(int j = 1; j < n; j++) {
                if(s[j][i] != ch) {
                    return pre;
                }
            }
            pre += ch;
        }
        return pre;
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
        vector<string> a(n);
        for(string &x : a) cin >> x;
        Solution sol;
        cout << sol.longestCommonPrefix(a);
    }
    return 0;
}