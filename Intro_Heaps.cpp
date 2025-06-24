/*
    Author: Dhruv Varshney
    Date - 2025/06/15
    Time - 16:24:07
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

class max_heap {

    void siftDown(vi &a, int idx) {
        int n = a.size(), lrg = idx;
        while(true) {
            int leftIdx = 2*idx + 1, rightIdx = 2*idx + 2;

            if(leftIdx < n && a[leftIdx] > a[lrg]) {
                lrg = leftIdx;
            }
            if(rightIdx < n && a[rightIdx] > a[lrg]) {
                lrg = rightIdx;
            }

            if(lrg == idx) {
                return;
            }

            swap(a[lrg], a[idx]);
            idx = lrg;
        }
    }

    void siftUp(vi &a, int idx) {
        while(idx > 0) {
            int pIdx = (idx-1)/2;
            if(a[pIdx] < a[idx]) {
                swap(a[pIdx], a[idx]);
                idx = pIdx;
            }
            else {
                break;
            }
        }
    }

    public:

    void insert(vi &h, int k) {
        h.push_back(k);

        siftUp(h, h.size()-1);
    }
    int extract_max(vi &a) {

        if(a.empty()) {
            return -1;
        }

        int top = a[0];
        a[0] = a.back();
        a.pop_back();

        if(!a.empty()) {
            siftDown(a, 0);
        }
        return top;
    }

    int find_max(vi &a) {
        if(a.empty()) {
            return INT_MAX;
        }
        return a[0];
    }

    void heapify(vi &a) {
        if(a.empty()) {
            return;
        }
        int n = a.size();
        // A cleaner and more robust heapify loop
        for (int i = n / 2 - 1; i >= 0; i--) {
            siftDown(a, i);
        }
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
        max_heap hp;
        hp.heapify(a);
        for(int x : a) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}