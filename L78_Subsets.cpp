/*
    Author: Dhruv Varshney
    Date - 2025/05/31
    Time - 12:26:08
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
    void genSubset(vi &a, vvi &res, vi &tem, int idx) {
        if(idx == a.size()) {
            res.push_back(tem);
            return;
        }
        genSubset(a, res, tem, idx + 1);
        tem.push_back(a[idx]);
        genSubset(a, res, tem, idx + 1);
        tem.pop_back();
    }
    public:
    vector<vector<int>> subsets(vector<int>& a) {
        vvi res;
        vi tem;
        genSubset(a, res, tem, 0);
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
        vi a(n);
        for(int &x : a) cin >> x;
        Solution sol;
        vvi res = sol.subsets(a);
        for(auto x : res) {
            for(int y : x) {
                cout << y << ' '; 
            }
            cout <<'\n';
        }
    }
    return 0;
}