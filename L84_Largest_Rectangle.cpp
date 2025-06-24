/*
    Author: Dhruv Varshney
    Date - 05/08/2025 
    Time - 09:27:53
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
public:
    int largestRectangleArea_bruteforce(vector<int>& h) {
        int n = h.size();
        int max_area = INT_MIN;
        for(int i = 0; i < n ; i++) {
            for(int j = i; j < n; j++) {
                int mini = INT_MAX;
                for(int k = i; k <= j ; k++) {
                    mini = min(h[k], mini);
                }
                max_area = max(max_area, mini * (j - i + 1));
            }
        }
        return max_area;
    }
    int largestRectangleArea(vi &h) {
        int n = h.size();
        stack<int> st;
        int nse[n], pse[n];

        for(int i = 0; i < n; i++) {
            while(!st.empty() && h[st.top()] >= h[i]) {
                st.pop();
            }
            if(st.empty()) pse[i] = 0;
            else pse[i] = st.top()+1;

            st.push(i);
        }
        
        while(!st.empty()) st.pop();

        for(int i = n - 1;i >= 0; i--) {
            while(!st.empty() && h[st.top()] >= h[i]) {
                st.pop();
            }
            if(st.empty()) nse[i] = n - 1;
            else nse[i] = st.top() - 1;

            st.push(i);
        }
        int maxi = INT_MIN;
        for(int i = 0; i < n ; i++) {
            maxi = max(maxi, (nse[i] - pse[i] + 1)*h[i]);
        }
        return maxi;
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _t = 1;
    cin >> _t; // Comment for single test case
    while (_t--) {
        int n; cin>>n;
        vi a(n);
        for(int &x : a) {
            cin >> x;
        }
        Solution sol;
        cout << sol.largestRectangleArea(a) << '\n';
    }
    return 0;
}