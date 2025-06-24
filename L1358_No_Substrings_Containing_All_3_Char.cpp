/*
    Author: Dhruv Varshney
    Date - 2025/05/15
    Time - 13:32:44
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
    int numberOfSubstrings(string s) {
        int freq[3] = {0};
        int sum = 0;
        for(int r = 0, l = 0; r < s.length() ; r++) {
            freq[s[r]-'a']++;
            while(freq[0] && freq[1] && freq[2]) {
                freq[s[l]-'a']--;
                l++;
            }
            sum+=l;
        }
        return sum;
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _t = 1;
    //cin >> _t;
    while (_t--) {
        string s;
        cin >> s;
        Solution sol;
        cout << sol.numberOfSubstrings(s) << '\n';
    }
    return 0;
}