/*
    Author: Dhruv Varshney
    Date - 2025/05/30
    Time - 21:48:51
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
    void strTOint(string &s, int &ans, int start, int end, int flagZero) {
        if(start == end) {
            return;
        }
        if(s[start] == ' ') {
            strTOint(s, ans, start + 1, end);
        }
        if(s[start] == '-') {
            ans *= -1;
        }
        if(flagZero) {
            if(s[start] == '0') {
                strTOint(s, ans, start + 1, end, flagZero);
            }
            else if(s[start] != '+' && s[start] != '-') {
                flagZero = 0;
                strTOint(s, ans, start, end, flagZero);
            }
        }
        else {
            int digit = s[start] - '0';
            ans = ans*10 + digit;
            strTOint(s, ans, start + 1, end, flagZero);
        }
    }
public:
    int myAtoi(string s) {
        int ans = 1;
        strTOint(s, ans, 0, s.length() - 1, 1);
        if(ans < -512) {
            ans = 512;
        }
        else if(ans > 511) {
            ans = 511;
        }
        return ans;
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
        
    }
    return 0;
}