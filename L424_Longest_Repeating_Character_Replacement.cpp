/*
    Author: Dhruv Varshney
    Date - 2025/05/15
    Time - 09:44:32
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
    int characterReplacement(string s, int k) {
        int n = s.length();
        int mp[26] = {0};
        int maxf = 0, len = 0;
        for(int r = 0, l = 0; r < n ; r++) {

            mp[s[r] - 'A']++;
            maxf = max(mp[s[r] - 'A'], maxf);

            while((r - l + 1) - maxf > k) {
                mp[s[l] - 'A']--;
                l++;
            }

            len = max(len, r - l + 1);
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
        string s;
        cin >> s;
        int n;
        cin >> n;
        Solution sol;
        cout << sol.characterReplacement(s, n) <<'\n';
    }
    return 0;
}