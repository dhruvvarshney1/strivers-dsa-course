/*
    Author: Dhruv Varshney
    Date - 2025/05/22
    Time - 23:34:50
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
    string reverseWords(string s) {
        stack<string> st;
        string tem;

        for(int i = 0; i < s.length(); i++) {
            if(s[i] == ' ') {
                if(tem.length() > 0) {
                    st.push(tem);
                    tem = "";
                }
                else {
                    continue;
                }
            }
            else {
                tem+= s[i];
            }
        }
        if(tem.length()) st.push(tem);
        tem = "";
        while(!st.empty()) {
            tem += st.top();
            st.pop();
            if(!st.empty()) tem+= ' ';
        }
        return tem;
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _t = 1;
    cin >> _t;
    cin.ignore();
    while (_t--) {
        string s;
        getline(cin, s);

        Solution sol;
        cout << sol.reverseWords(s) <<'\n';
    }
    return 0;
}