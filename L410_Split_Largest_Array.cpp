/*
    Author: Dhruv Varshney
    Date - 2025/05/22
    Time - 22:20:40
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
    int divArr(vector<int> &a, int m) {
        int n = a.size();
        int sum = 0, cnt = 1;
        for(int i = 0; i < n ; i++) {
            if(sum + a[i] <= m) {
                sum += a[i];
            }
            else {
                cnt++;
                sum = a[i];
            }
        }
        return cnt;
    }
public:
    int splitArray(vector<int> &a, int k) {
        int n = a.size();
        int lo = *max_element(a.begin(), a.end()), hi = 0;
        for(int x : a) {
            hi += x;
        }
        while(lo <= hi) {
            int m = lo + (hi - lo)/2;
            if(divArr(a, m) > k) {
                lo = m + 1;
            }
            else {
                hi = m - 1;
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
        int n, k;
        cin >> n >> k;
        vi a(n);
        for(int &x : a) cin >> x;
        Solution sol;
        cout << sol.splitArray(a, k) << '\n';        
    }
    return 0;
}