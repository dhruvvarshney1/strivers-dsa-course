/*
    Author: Dhruv Varshney
    Date - 2025/05/21
    Time - 23:09:38
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
private:
    int calcHours(vi &a, int k) {
        int sum = 0;
        for(int i = 0; i < a.size() ; i++) {
            if(a[i] <= k) {
                sum++;
            }
            else {
                sum += (a[i] + k - 1) / k;
            }
        }
        return sum;
    }
public:
    int minEatingSpeed(vi &a, int h) {
        int vmax = *max_element(a.begin(), a.end());
        int l = 1, r = vmax, k;
        while(l <= r) {
            int m = l + (r - l)/2;
            k = calcHours(a, m);
            if(k <= h) {
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        return l;
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
        cout << sol.minEatingSpeed(a, k);
    }
    return 0;
}