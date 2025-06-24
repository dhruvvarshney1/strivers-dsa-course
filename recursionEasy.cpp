/*
    Author: Dhruv Varshney
    Date - 2025/05/30
    Time - 17:19:30
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
    void revString(string &s, int start, int end) {
        if(start >= end) {
            return;
        }
        swap(s[start], s[end]);
        return revString(s, start + 1, end - 1);
    }
    public:
    // Beginner Level
    int sumN(int n) {
        if(n == 0) {
            return 0; 
        }

        return n + sumN(n - 1);
    }

    string reverse_string(string s) {
        revString(s, 0, s.length() - 1);
        return s;
    }

    int pwr(int x, int n) {
        if(n == 0) {
            return 1;
        }
        return x * pwr(x,n - 1);
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _t = 1;
    //cin >> _t;
    while (_t--) {
        int x, n;
        cin >> x >> n;
        Solution sol;
        cout << sol.pwr(x, n) << '\n';
    }    
    return 0;
}