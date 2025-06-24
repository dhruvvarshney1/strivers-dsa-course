/*
    Author: Dhruv Varshney
    Date - 2025/06/05
    Time - 10:22:55
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

struct node {
    int val;
    node* left;
    node* right;

    node(int data) {
        val = data;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    BSTIterator(node* root) {
        
    }
    
    int next() {
        
    }
    
    bool hasNext() {
        
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