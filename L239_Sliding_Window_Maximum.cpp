/*
    Author: Dhruv Varshney
    Date - 2025/05/09
    Time - 17:10:37
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
    vi maxSlidingWindow_bruteForce(vi &a, int k) {
        int n = a.size();
        vi ans;
        for(int i = 0; i <= n - k; i++) {
            int maxi = INT_MIN;
            for(int j = i; j < i + k; j++) {
                maxi = max(a[j], maxi);
            }
            ans.push_back(maxi);
        }
        return ans;
    }

    vi maxSlidingWindow(vi &a, int k) {
        int n = a.size();
        vi l(n - k);
        dqi dq;
        for(int i = 0; i < n ; i++) {
            
        }
        
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _t = 1;
    cin >> _t; // Comment for single test case
    while (_t--) {
        int n, k;
        cin >> n >> k;
        vi a(n);
        for(int &x : a) cin >> x;
        Solution sol;
        vi b = sol.maxSlidingWindow(a, k);
        for(int y : b) cout << y << ' ';
        cout <<'\n';
    }
    return 0;
}