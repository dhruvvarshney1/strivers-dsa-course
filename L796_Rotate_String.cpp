/*
    Author: Dhruv Varshney
    Date - 2025/06/06
    Time - 13:15:29
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
    bool rotateString(string s, string g) {
        if(s.length() != g.length()) {
            return false;
        }

        string tem = s + s;
        return tem.find(g) != string :: npos;
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _t = 1;
    //cin >> _t;
    while (_t--) {
        string s, g;
        cin >> s >> g;
    
        Solution sol;
        cout << boolalpha << sol.rotateString(s, g) << '\n';    
    }
    return 0;
}