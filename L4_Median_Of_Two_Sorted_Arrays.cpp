/*
    Author: Dhruv Varshney
    Date - 2025/05/24
    Time - 21:25:46
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
public:
    double findMedianSortedArrays_bruteforce(vector<int>&a, vector<int>&b) {
        int n = a.size(), m = b.size();
        int i = 0, j = 0;
        vector<int> c;
        while(i < n && j < m) {
            if(a[i] < b[j]) {
                c.push_back(a[i]);
                i++;
            }
            else if(a[i] > b[j]) {
                c.push_back(b[j]);
                j++;
            }
            else {
                c.push_back(a[i]);
                c.push_back(b[j]);
                i++;
                j++;
            }
        }
        while(i < n) {
            c.push_back(a[i]);
            i++;
        }
        while(j < m) {
            c.push_back(b[j]);
            j++;
        }

        if((n + m) % 2 == 0) {
            return (double)(c[(n+m-1)/2] + c[(n+m+1)/2])/2.0;
        }
        return c[(n+m)/2];
    }
    double findMedianSortedArrays(vector<int>&a, vector<int>&b) {
        int n = a.size(), m = b.size();
        int l1 = 0, r1 = n - 1, l2 = 0, r2 = m - 1;
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _t = 1;
    cin >> _t;
    while (_t--) {
        int n, m;
        cin >> n >> m;
        vi a(n), b(m);
        for(int &x : a) cin >> x;
        for(int &y : b) cin >> y;
        Solution sol;
        cout << sol.findMedianSortedArrays(a, b) << '\n';
    }
    return 0;
}