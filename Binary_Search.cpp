/*
    Author: Dhruv Varshney
    Date - 2025/05/09
    Time - 00:04:23
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
private:
    int search(vi &a, int k) {
        int n = a.size();
        int l = 0, r = n - 1;
        while(l <= r) {
            int m = l + (r - 1) / 2;
            if(a[m] == k) {
                return m;
            }
            else if(a[m] < k) {
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }

        return -1;
    }
    int Lower_Bound(vi &a, int k) {
        int n = a.size();
        int l = 0, r = n - 1, idx;
        while(l <= r) {
            int m = l + (r - 1)/2;
            if(a[m] >= k) {
                r = m - 1;
                idx = m;
            }
            else {
                l = m + 1;
            }
        }
        return idx;
    }
    int Upper_Bound(vi &a, int k) {
        int n = a.size();
        int l = 0, r = n - 1, idx;
        while(l <= r) {
            int m = l + (r - 1)/2;
            if(a[m] > k) {
                r = m - 1;
                idx = m;
            }
            else {
                l = m + 1;
            }
        }
        return idx;
    }
public:
    int rotatedSearch(vi &a, int k) {
        int n = a.size();
        int l = 0, r = n - 1;
        while(l <= r) {
            int m = l + (r - 1)/2;

            if(a[m] == k) return m;
            if(a[l] <= a[m]) {
                if(a[l] <= k && k <= a[m]) {
                    r = m - 1;
                }
                else {
                    l = m + 1;
                }
            }
            else {
                if(a[m] <= a[r]) {
                    if(a[m] <= k && k <= a[r]) {
                        l = m + 1;
                    }
                    else {
                        r = m - 1;
                    }
                }
            }
        }
        return -1;
    }
    int findRotation(vi &a) {
        int n = a.size();
        int l = 0, r = n - 1, idx = -1, ele = INT_MAX;
        while(l <= r) {
            int m = l + (r - 1)/2;
            if(a[l] <= a[r]) {
                idx = l;
                ele = a[l];
                break;
            }

            if(a[l] <= a[m]) {
                if(a[l] < ele) {
                    ele = a[l];
                    idx = l;
                }
                l = m + 1;
            }
            else if(a[m] <= a[r]) {
                if(a[m] < ele) {
                    ele = a[m];
                    idx = m;
                }
                r = m - 1;
            }
        }
        return idx;
    }
    int nonDuplicate(vi &a) {
        int n = a.size();
        if(n == 1 || a[0] != a[1]) {
            return a[0];
        }
        if(a[n - 2] != a[n-1]) {
            return a[n- 1];
        }
        int l = 0, r = n - 2;
        while (l <= r) {
            int m = l + (r - 1)/2;
            if(a[m] != a[m-1] && a[m] != a[m+1]) {
                return a[m];
            }
            if((m % 2 == 1 && a[m] == a[m-1]) || (m % 2 == 0 && a[m] == a[m+1])) {
                l=m+1;
            }
            else {
                r=m-1;
            }
        }
        return -1;
    }
    int findPeakElement(vi &a) {
        int n = a.size();
        if(n == 1) return 0;
        if(a[0] > a[1]) return 0;
        if(a[n-2] < a[n-1]) return n-1;
        int l = 1, r = n - 2;
        while(l <= r) {
            int m = l + (r - l)/2;
            if(a[m-1] < a[m] && a[m] < a[m+1]) {
                return m+1;
            }
            if(a[m-1] < a[m]) {
                l=m+1;
            }
            else {
                r=m-1;
            }
        }
        return -1;
    }
    
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _t = 1;
    // cin >> _t; // Comment for single test case
    while (_t--) {
        int n;
        cin >> n;
        vi a(n);
        for(int &x : a) cin >> x;
        Solution sol;
        cout << sol.findPeakElement(a) <<'\n';
    }
    return 0;
}