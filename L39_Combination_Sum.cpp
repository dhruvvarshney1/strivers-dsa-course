/*
    Author: Dhruv Varshney
    Date - 2025/06/01
    Time - 22:43:11
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
    void genCombo(vi &a, int k, vector<vector<int>> &res, vi &tem, int sum, int idx) {
        if(sum == k) {
            res.push_back(tem);
            return;
        }

        for(int i = idx; i < a.size(); i++) {
            // Skip duplicates at the same recursion level
            if(i > idx && a[i] == a[i-1]) continue;

            // Pruning: if adding current element exceeds target, break
            if(sum + a[i] > k) break;
            
            tem.push_back(a[i]);
            genCombo(a, k, res, tem, sum + a[i], i + 1);
            tem.pop_back();
        }
    } 
public:
    vector<vector<int>> combinationSum2(vector<int>& candi, int k) {   
        sort(candi.begin(), candi.end());
        vector<vector<int>> res;
        vi tem;
        genCombo(candi, k, res, tem, 0, 0);
        return res;
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
        vvi res = sol.combinationSum2(a, k);
        for(auto x : res) {
            for(int y : x) {
                cout << y << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}