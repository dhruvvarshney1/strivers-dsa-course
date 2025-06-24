/*
    Author: Dhruv Varshney
    Date - 2025/06/07
    Time - 08:52:30
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
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for(char ch : s) {
            freq[ch]++;
        }

        vector<string> a;
        for(auto [k, v]: freq) {
            string tem;
            for(int i = 0; i < v; i++) {
                tem += k;
            }
            a.push_back(tem);        
        }
        
        sort(a.begin(), a.end(), [](const string& a, const string& b) {
        return a.length() > b.length();
        });
        string ans = "";
        for (const string& chunk : a) {
            ans += chunk;
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
        string s;
        cin >> s;

        Solution sol;
        cout << sol.frequencySort(s) <<'\n';
    }
    return 0;
}