/*
    Author: Dhruv Varshney
    Date - 2025/05/15
    Time - 11:54:42
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
    int sumlessthan(vector<int>&a, int k) {
        int sum = 0, count = 0;
        if(k < 0) return 0;
        for(int r = 0, l = 0; r < a.size(); r++) {
            sum += a[r];
            while(sum > k) {
                sum -= a[l];
                l++;
            }
            count += (r - l + 1);
        }

        return count;
    }
public:
    int numSubarraysWithSum(vi &a, int k) {
        return sumlessthan(a, k) - sumlessthan(a, k - 1);
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
        cout << sol.numSubarraysWithSum(a, k) <<'\n';
    }
    return 0;
}