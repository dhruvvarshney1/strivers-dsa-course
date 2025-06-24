/*
    Author: Dhruv Varshney
    Date - 2025/05/14
    Time - 09:27:08
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
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int len = 0;
        unordered_set<char> us;
        for(int r = 0, l = 0; r < n; r++) {
            if(us.find(s[r]) != us.end()) {
                while(l < r && us.find(s[r]) != us.end()) {
                    us.erase(s[l]);
                    l++;
                }
            }
            us.insert(s[r]);
            len = max(len,r - l + 1);
        }
        return len;
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _t = 1;
    cin >> _t; // Comment for single test case
    while (_t--) {
        Solution sol;
        string s;
        cin >> s;
        int l = sol.lengthOfLongestSubstring(s);
        cout << l << '\n';
    }
    return 0;
}