/*
    Author: Dhruv Varshney
    Date - 2025/06/06
    Time - 09:21:08
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
    bool isIsomorphic(string s, string t) {
        int n = s.length();

        if(s == t) {
            return true;
        }

        if(s.empty() || t.empty()) {
            return false;
        }

        vector<int> ht(256, 0), hs(256, 0);
        for(int i = 0; i < n;i++) {
            if(ht[t[i]] != hs[s[i]]){
                return false;
            }
            ht[t[i]] = hs[s[i]] = i + 1; 
        }
        return true;
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _t = 1;
    //cin >> _t;
    while (_t--) {
        Solution sol;

        string s, t;
        cin >> s >> t;
        
        cout << boolalpha << sol.isIsomorphic(s, t) << '\n';
    }
    return 0;
}