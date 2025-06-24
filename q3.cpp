/*
    Author: Dhruv Varshney
    Date - 05/06/2025
    Time - 17:01:04
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long

// UTILS
typedef vector<int> vi;
typedef stack<int> sti;
typedef queue<int> qi;
typedef set<int> si;
typedef unordered_set<int> usi;
typedef map<int, int> mii;
typedef unordered_map<int, int> umii;

const int mod = 7 + 1e9;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        sti s;
        for (int x : a) {
            bool alive = true;
            while (!s.empty() && x < 0 && s.top() > 0) {
                if (abs(x) > s.top()) {
                    s.pop();
                } else if (abs(x) == s.top()) {
                    s.pop();
                    alive = false;
                    break;
                } else {
                    alive = false;
                    break;
                }
            }
            if (alive) {
                s.push(x);
            }
        }
        vi ans(s.size());
        for (int i = s.size() - 1; i >= 0; --i) {
            ans[i] = s.top();
            s.pop();
        }
        return ans;
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _t = 1;
    //  cin >> _t; // Comment for single test case
    while (_t--) {
        int n;
        cin >> n;
        vi a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution s;
        vi ans = s.asteroidCollision(a);
        for (int x : ans) {
            cout << x << ' ';
        }
        cout << '\n';
    }
    return 0;
}
