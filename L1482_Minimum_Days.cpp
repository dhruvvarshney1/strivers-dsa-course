/*
    Author: Dhruv Varshney
    Date - 2025/05/21
    Time - 23:58:00
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
    bool adjBouquet(vector<int> &a, int d, int m, int k) {
        int c = 0, nb = 0;
        for(int i = 0; i < a.size() ; i++) {
            if(a[i] <= d) {
                c++; 
            }
            else {
                nb += (c / k);
                c = 0;
            }
        }
        nb += (c / k);
        return nb >= m;
    }
public:
    int minDays(vector<int> &a, int m, int k) {
        int n = a.size();
        if((long long)m*k > a.size()) {
            return -1;
        }

        long long hi = 0, lo = 1;
        hi = *max_element(a.begin(), a.end());
        
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if(adjBouquet(a, mid, m, k)) {
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }
        }
        return lo;
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _t = 1;
    //cin >> _t;
    while (_t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vi a(n);
        for(int &x : a) cin >> x;
        Solution sol;
        cout << sol.minDays(a, m , k) << '\n';
    }
    return 0;
}