/*
    Author: Dhruv Varshney
    Date - 2025/05/22
    Time - 23:07:03
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
    int allocateBooks(vector<int> &a,int k) {
        int cnt = 1, sum = 0;
        for(int i = 0; i < a.size() ; i++) {
            if(sum + a[i] <= k) {
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
    int findPages(vector<int> &a, int m) {
        int lo = *max_element(a.begin(), a.end()), hi = 0;
        for(int x : a) hi += x;
        while(lo <= hi) {
            int mid = lo + (hi - lo)/2;
            if(allocateBooks(a, mid) <= m) {
                hi = mid - 1;
            }
            else {
                lo = mid+1;
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
        int n, m;
        cin >> n >> m;
        vi a(n);
        for(int &x : a) cin >> x;
        Solution sol;
        cout << sol.findPages(a, m) << '\n';        
    }
    return 0;
}