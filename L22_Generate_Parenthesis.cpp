/*
    Author: Dhruv Varshney
    Date - 2025/05/28
    Time - 15:41:44
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
    void drawBracket(string s, int n, int open, int close, vector<string> &res) {
        if(open == n && close == n) {
            res.push_back(s);
            return;
        }
        if(open == close) {
            drawBracket(s + '(', n, open + 1, close, res);
        }
        if(open > close) {

            if(open < n) drawBracket(s + '(', n, open + 1, close, res);

            drawBracket(s + ')', n, open, close + 1, res);
        }
    }
    public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s = "";
        drawBracket(s, n, 0, 0, res);
        return res;
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
        vector<string> res;
        Solution sol;
        res = sol.generateParenthesis(n);
        for(string x : res) {
            cout << x << '\n';
        }
    }
    return 0;
}