/*
    Author: Dhruv Varshney
    Date - 2025/05/14
    Time - 12:13:01
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
    int longestOnes(vector<int> &a, int k) {
        int n = a.size();
        int zr = 0, len = 0;
        for(int l = 0, r = 0; r < n ; r++) {
            if(a[r] == 0) zr++;
            while(zr > k) {
                if(a[l] == 0) zr--;
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
    // cin >> _t; // Comment for single test case
    while (_t--) {
        int n, k;
        cin >> n >> k;
        vi a(n);
        for(int &x : a) cin >> x;
        Solution sol;
        cout << sol.longestOnes(a, k) << '\n';
    }
    return 0;
}