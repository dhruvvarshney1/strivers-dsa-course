/*
    Author: Dhruv Varshney
    Date - 05/07/2025 
    Time - 21:57:30
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
    long long subArrayRanges_brute_force(vector<int>& a) {
        int n = a.size();
        int sum = 0;
        for(int i = 0; i < n ; i++) {
            for(int j = i; j < n ; j++) {
                int l = INT_MIN, s = INT_MAX;
                for(int k = i; k <= j; k++) {
                    l = max(l, a[k]);
                    s = min(s, a[k]);
                }
                sum += (l - s);
            }
        }
        return sum;
    }

    vector<int> nseIdx1(vector<int>& a) {
        int n = a.size();
        stack<int> s;
        vector<int> res(n);
        
        for(int i = n - 1; i >= 0; i--) {
            while(!s.empty() && a[s.top()] >= a[i]) {
                s.pop();
            }
            if(s.empty()) res[i] = n;
            else res[i] = s.top();
            
            s.push(i);
        }
        
        return res;
    }

    vector<int> pseIdx1(vector<int>& a) {
        int n = a.size();
        stack<int> s;
        vector<int> res(n);
        
        for(int i = 0; i < n; i++) {
            while(!s.empty() && a[s.top()] > a[i]) {
                s.pop();
            }
            if(s.empty()) res[i] = -1;
            else res[i] = s.top();
            
            s.push(i);
        }
        
        return res;
    }

    int sumSubarrayMins(vector<int>& a) {
        int n = a.size();
        long long sum = 0;
        
        vector<int> pse = pseIdx1(a);
        vector<int> nse = nseIdx1(a);
        
        for(int i = 0; i < n; i++) {
            long long l = i - pse[i];
            long long r = nse[i] - i;
            sum = (sum + (l * r ) *a[i]);
        }
        
        return sum;
    }

    vector<int> nseIdx2(vector<int>& a) {
        int n = a.size();
        stack<int> s;
        vector<int> res(n);
        
        for(int i = n - 1; i >= 0; i--) {
            while(!s.empty() && a[s.top()] <= a[i]) {
                s.pop();
            }
            if(s.empty()) res[i] = n;
            else res[i] = s.top();
            
            s.push(i);
        }
        
        return res;
    }

    vector<int> pseIdx2(vector<int>& a) {
        int n = a.size();
        stack<int> s;
        vector<int> res(n);
        
        for(int i = 0; i < n; i++) {
            while(!s.empty() && a[s.top()] < a[i]) {
                s.pop();
            }
            if(s.empty()) res[i] = -1;
            else res[i] = s.top();
            
            s.push(i);
        }
        
        return res;
    }

    int sumSubarrayMaxs(vector<int>& a) {
        int n = a.size();
        long long sum = 0;

        vector<int> pse = pseIdx2(a);
        vector<int> nse = nseIdx2(a);
        
        for(int i = 0; i < n; i++) {
            long long l = i - pse[i];
            long long r = nse[i] - i;
            sum = (sum + (l * r ) *a[i]);
        }
        
        return sum;
    }

    long long subArrayRanges(vector<int>& a) {
        int n = a.size();
        return sumSubarrayMaxs(a) - sumSubarrayMins(a);
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    Solution sol; // Create an instance of the Solution class
    
    vector<int> a;
    int n, temp;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> temp;
        a.push_back(temp);
    }

    long long result = sol.subArrayRanges(a);
    cout << result << endl;

    return 0;
}
