/*
    Author: Dhruv Varshney
    Date - 2025/05/16
    Time - 19:46:03
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
    int atmostK(vector<int>& a, int k) {
        int n = a.size();
        int ans = 0,dist = 0;
        umii hsh;
        for(int r = 0, l = 0; r < n ; r++) {
            if(hsh[a[r]] == 0) {
                dist++;
            }
            hsh[a[r]]++;
            while(dist > k) {
                hsh[a[l]]--;
                if(hsh[a[l]] == 0) dist--;
                l++;
            }
            ans += (r - l + 1);
        }
        return ans;
    }
public:
    int subarraysWithKDistinct(vector<int>& a, int k) {
        return atmostK(a, k) - atmostK(a, k-1);
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
        cout << sol.subarraysWithKDistinct(a, k) << '\n';        
    }
    return 0;
}