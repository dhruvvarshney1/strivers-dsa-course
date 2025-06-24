/*
    Author: Dhruv Varshney
    Date - 2025/05/15
    Time - 23:25:33
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
    int maxScore(vector<int>& c, int k) {
        int lsum = 0, rsum = 0, maxSum = INT_MIN;
        for(int i = 0; i < k ; i++) {
            lsum += c[i];
        }
        maxSum = lsum;
        int rIdx = c.size() - 1;
        for(int i = 0; i < k ; i++) {
            lsum -= c[k - i - 1];
            rsum += c[rIdx - i];
            maxSum = max(lsum + rsum , maxSum);
        }
        return maxSum;
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _t = 1;
    //cin >> _t;
    while (_t--) {
        int n, k;
        cin >> n >> k;
        vi a(n);
        for(int &x : a) cin >> x;
        Solution sol;
        cout << sol.maxScore(a, k) << '\n';
    }
    return 0;
}