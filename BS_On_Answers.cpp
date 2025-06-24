/*
    Author: Dhruv Varshney
    Date - 2025/05/11
    Time - 01:06:20
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
typedef deque<int> dqi;

const int mod = 7 + 1e9;

class Solution {
public:
    int floorSqrt(int n) {
        int l = 2, r = n / 2;
        int ans;
        while(l <= r) {
            int m = l + (r - l)/2;
            if(m*m <= n) {
                ans = m;
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        return ans;
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _t = 1;
    cin >> _t; // Comment for single test case
    while (_t--) {
        int n;
        cin >> n;
        vi a(n);
        for(int &x : a) cin >> x;
        Solution sol;
        cout << sol.
    }
    return 0;
}