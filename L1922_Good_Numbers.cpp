/*
    Author: Dhruv Varshney
    Date - 2025/05/20
    Time - 22:40:34
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

const long long mod = 7 + 1e9;

class Solution {
private:
    long long modPow(long long num, long long exp, long long mod) {
        if(exp == 0) return 1;

        long long halfPow = modPow(num, exp / 2, mod);
        if(exp % 2 == 0) {
            return ((halfPow % mod) * (halfPow % mod)) % mod;
        }
        else {
            long long p = (((halfPow % mod) * (halfPow % mod)) % mod);
            return ((p % mod) * (num % mod)) % mod;
        }
    }
public:
    long long countGoodNumbers(long long n) {
        long long res = (modPow(5, (n + 1)/ 2, mod) % mod * modPow(4, n / 2, mod) % mod) % mod;
        return res;
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _t = 1;
    //cin >> _t;
    while (_t--) {
        int n;
        cin >> n;
        // vi a(n);
        // for(int &x : a) cin >> x;
        Solution sol;
        cout << sol.countGoodNumbers(n) <<'\n';        
    }
    return 0;
}