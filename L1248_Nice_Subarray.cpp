/*
    Author: Dhruv Varshney
    Date - 2025/05/15
    Time - 12:33:03
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
    int atmostK(vector<int>&a, int k) {
        if(k < 0) return 0;
        int count_odd = 0, count_nice = 0;
        for(int l = 0, r = 0; r < a.size() ; r++) {
            if(a[r] & 1) count_odd++;
            while(count_odd > k) {
                if(a[l] & 1) count_odd--;
                l++;
            }
            count_nice += (r - l + 1) ;
        }
        return count_nice;
    }
public:
    int numberOfSubarrays(vector<int> &a, int k) {
        return atmostK(a, k) - atmostK(a, k - 1);
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
        cout << sol.numberOfSubarrays(a, k) << '\n';
    }
    return 0;
}