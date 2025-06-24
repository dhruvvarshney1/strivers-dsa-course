/*
    Author: Dhruv Varshney
    Date - 05/08/2025 
    Time - 08:39:36
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
// UTILS
typedef vector<int> vi;
typedef set<int> si;
typedef unordered_set<int> usi;
typedef map<int, int> mii;
typedef unordered_map<int, int> umii;

const int mod = 7 + 1e9;

class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        stack<char> st;
        string res = "";
        for(int i = 0; i < n ; i++) {
            while(!st.empty() && k > 0 && num[i] < st.top()) {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(k > 0) {
            st.pop();
            k--;
        }
        while(!st.empty()) {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());

        int leadingZeros = 0;
        while (leadingZeros < res.length() - 1 && res[leadingZeros] == '0') {
            leadingZeros++;
        }
        res = res.substr(leadingZeros);
        
        return res.empty() ? "0" : res;
    }
};


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _t = 1;
    cin >> _t; // Comment for single test case
    while (_t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution sol;
        cout << sol.removeKdigits(s, k) << '\n';
    }
    return 0;
}