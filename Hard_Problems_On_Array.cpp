/*
    Author: Dhruv Varshney
    Date - 2025/05/16
    Time - 09:36:07
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
    vvi generate(int n) {
        vector<vector<int>> p;
        if (n == 0) return p;
        p.push_back({1});
        if (n == 1) return p;
        p.push_back({1, 1});
        for(int i = 2; i < n ; i++) {
            vector<int> ro(i + 1);
            for(int j = 0; j < i + 1; j++) {
                if(j == 0 || j == i) {
                    ro[j] = 1;
                }
                else {
                    ro[j] = p[i-1][j-1] + p[i-1][j];
                }
            }
            p.push_back(ro);
        }
        return p;
    }
    vector<int> majorityElement_hashing(vector<int>& a) {
        int n =a.size();
        std::unordered_map<int, int> counts;
        for (int num : a) {
            counts[num]++;
        }

        std::vector<int> result;
        int threshold = n / 3;
        for (auto const& [element, count] : counts) {
            if (count > threshold) {
                result.push_back(element);
            }
        }

        return result;
    }
    vector<int> majorityElement(vector<int> &a) {
        int n = a.size();
        int candi1, candi2, cnt1 = 0, cnt2 = 0;
        for(int x : a) {
            if(cnt1 == 0 && x != candi2) {
                cnt1 = 1;
                candi1 = x;
            }
            else if(cnt2 == 0 && x != candi1) {
                cnt2 = 1;
                candi2 = x;
            }
            else if(x == candi1) cnt1++;
            else if(x == candi2) cnt2++;
            else {
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0, cnt2 = 0;
        for(int x : a) {
            if(x == candi1) {
                cnt1++;
            }
            if(x == candi2) {
                cnt2++;
            }
        }
        vi v;
        if(cnt1 > a.size() / 3) {
            v.push_back(candi1);
        }
        if(cnt2 > a.size() / 3) {
            v.push_back(candi2);
        }
        return v;
    }
    vector<vector<int>> threeSum(vector<int>& a) {
        int n = a.size();
        
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
        for(int &x : a) cin >>x;
        Solution sol;
        vi b = sol.majorityElement(a);
        for(int &x : b) {
            cout << x << ' ';
        }
        cout << '\n';
        // for(int i = 0; i < n ; i++) {
        //     for(int j = 0; j < res[i].size(); j++) {
        //         cout << res[i][j] << ' ';
        //     }
        //     cout <<'\n';
        // }        
    }
    return 0;
}