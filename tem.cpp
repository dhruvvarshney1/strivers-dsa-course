/*
    Author: Dhruv Varshney
    Date - 05/02/2025 
    Time - 22:43:16
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vi;
typedef set<int> si;
const int mod = 7 + 1e9;

vector<int> nseIdx1(vector<int>& a) {
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


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _t = 1;
    // cin >> _t; // Comment for single test case
    while (_t--) {
        vi a = {2, 1, 5, 6, 2, 3};
        vi b = pseIdx1(a);
        for(int x : b) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}