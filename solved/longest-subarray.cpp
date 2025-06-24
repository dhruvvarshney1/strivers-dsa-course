/*
    Author: Dhruv Varshney
    Date - 05/01/2025 
    Time - 09:41:53
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vi;
typedef set<int> si;
const int mod = 7 + 1e9;

int longestSubarray_wrong(vi &a, int n, int k) {
    vi p(n, 0);
    p[0] = a[0];
    int idx = 0;
    for(int i = 1; i < n; i++) {
        p[i] = p[i - 1] + a[i];
        if(p[i] == k) {
            idx = i;
        }
    }
    return idx + 1;
}
int longestSubarray_bruteforce(vi &a, int n, int t) {
    int len = INT_MIN;
    for(int i = 0; i < n ; i++) {
        for(int j = i; j < n ;j++) {
            int s = 0;
            for(int k = i; k <= j ; k++) {
                s += a[k];
            }
            if(s == t)
                len = max(len, j - i + 1);
        }
    }
    return len;
}

int longestSubarray(vi &a, int n, int k) {

    // Positives only
    
    int l = 0,r = 0, sum = a[0], maxLen = 0;
    for(r= 0; r < n ; r++) {
        while(l <= r && sum > k) {
            sum -= a[l];
            l++;
        }

        if(sum == k) {
            maxLen = max(maxLen, r - l + 1);
        }

        if(r < n) sum += a[r];
    }

    return maxLen;
}
int longestSubarray1(vi &a, int n, int t) {

    // For positives, negatives and zeroes
    
    unordered_map<int, int> h;

    int sum = 0;
    int len = INT_MIN;
    for(int i = 0; i < n ; i++) {
        sum += a[i];

        if(sum == t) {
            len = max(len, i + 1);
        }

        if(h.find(sum - t) != h.end()) {
            len = max(len, i - h[sum - t]);
        }

        if(h.find(sum) == h.end()) {
            h[sum] = i;
        }
    }
    return len;
}
void solve() {
    int n, k;
    cin >> n >> k;
    vi arr(n);
    for(int &x : arr) cin >> x;
    int res = longestSubarray(arr, n, k);
    cout << res << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _t = 1;
    cin >> _t; // Comment for single test case
    while (_t--) {
        solve();
    }
    return 0;
}