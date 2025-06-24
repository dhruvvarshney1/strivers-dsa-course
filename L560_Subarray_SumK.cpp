/*
    Author: Dhruv Varshney
    Date - 05/08/2025 
    Time - 13:29:49
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

const int mod = 7 + 1e9;

class Solution {
public:
    int subarraySum_bruteforce(vi &a, int target) {
        int n = a.size(), c = 0;
        for(int i = 0; i < n ; i++) {
            for(int j = i; j < n ; j++) {
                int sum = 0;
                for(int k = i ; k <= j ; k++) {
                    sum += a[k];
                }
                if(sum == target) {
                    c++;
                }
            }
        }
        return c;
    }

    int subarraySum(vi &a, int t) {
        int n = a.size();
        mii mp;
        int sum = 0, c = 0;

        mp[0] = 1;
        for(int i = 0;i < n;i++) {
            sum += a[i];
            c += mp[sum - t];
            mp[sum] += 1;
        }
        return c;
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
        cout << sol.subarraySum(a, k) << '\n';
    }
    return 0;
}