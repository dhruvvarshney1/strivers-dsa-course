/*
    Author: Dhruv Varshney
    Date - 2025/05/22
    Time - 21:58:50
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
    int sumRem(vector<int> &a, int k) {
        int sum = 0;
        for(int i = 0; i < a.size(); i++) {
            sum += (a[i] + k - 1) / k;
        }
        return sum;
    }
public:
    int smallestDivisor(vi &a, int th) {
        int n = a.size();
        int l = 1, h = *max_element(a.begin(), a.end());
        while(l <= h) {
            int m = l + (h - l)/2;
            if(sumRem(a, m) <= th) {
                h = m - 1;
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
        cout << sol.smallestDivisor(a, k) << '\n';
    }
    return 0;
}