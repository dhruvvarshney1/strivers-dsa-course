# include <bits/stdc++.h>

using namespace std;

class solution {
public:
    bool binSearch1(vector<int> &a, int x) {
        int l = 0, r = a.size();
        while(l <= r) {
            int k = (l + r) / 2;

            if(a[k] == x)
                return true;
            else if(a[k] < x)
                l = k + 1;
            else
                r = k - 1;
        }
        return false;
    }

    bool binSearch2(vector<int> &a, int x) {
        int k = 0, n = a.size();
        for(int i = n / 2; i >= 1; i /= 2) {
            while(k + i < n && a[k + i] <= x) k += i;
        }
        if(a[k] == x) return true;

        return false;
    }

    int lowerbound(vector<int> &a, int k) {
        int n = a.size();
        int l = 0, r = n - 1, lb;
        while(l <= r) {
            int m = (l + r) / 2;
            if(a[m] >= k) {
                lb = m;
                r = m - 1;
            }
            else {
                l = m +1;
            }
        }
        return lb;
    }
    int upperbound(vector<int> &a, int k) {
        int l = 0, r = a.size() - 1, ub;
        while(l <= r) {
            int m = (l + r) / 2;
            if(a[m] > k) {
                ub = m;
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        return ub;
    }

    int search(vector<int>& a, int k) {
        int n = a.size();
        int l = 0, r = n - 1;
        while(l < r) {
            int m = (l + r) / 2;
            if(a[m] == k) {
                return m;
            }
            else if(a[m] < k) {
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }
        return -1;
    }

    int findFloor(vector<int> &a, int k) {
        int n = a.size();
        int l = 0, r = n - 1, ans = -1;
        while(l <= r) {
            int m = l + (r - 1) / 2;
            if(a[m] >= k) {
                ans = m;
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        return ans;
    }

    vector<int> getFloorandCeil(vector<int> &a, int k) {
        int n = a.size();
        int l = 0, r = n - 1, res1 = -1, res2 = -1;
        sort(a.begin(), a.end());
        while(l <= r) {
            int m = l + (r - 1) / 2;
            if(a[m] >= k) {
                res1 = a[m];
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        l = 0, r = n - 1;
        while(l <= r) {
            int m = l + (r - 1)/ 2;
            if(a[m] <= k) {
                res2 = a[m];
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }
        return {res2, res1};        
    }

    int searchInsert(vector<int> &a, int k) {
        int n = a.size();
        int l = 0, r = n - 1, ans = n;
        while(l <= r) {
            int m = (l + r) / 2;
            if(a[m] >= k) {
                ans = m;
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        return ans;                
    }

    vector<int> searchRange(vector<int> & a, int k) {
        int n = a.size();
        int l = 0, r = n - 1,lo = -1, hi = -1;
        // Checking for first occurence
        while(l <= r) {
            int m = (l + r) / 2;
            if(a[m] == k) {
                lo = m;
                r = m - 1;
            }
            else if(a[m] > k){
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        // Checking for last occurence
        l = 0, r = n - 1;
        while(l <= r) {
            int m = (l + r)/ 2;
            if(a[m] == k) {
                hi = m;
                l = m + 1;
            }
            else if(a[m] > k) {
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        return {lo, hi};
    }
    int countfreq(vector<int> &a, int k) {
        int n = a.size();
        int l = 0, r = n - 1,lo = -1, hi = -1;
        // Checking for first occurence
        while(l <= r) {
            int m = (l + r) / 2;
            if(a[m] == k) {
                lo = m;
                r = m - 1;
            }
            else if(a[m] > k){
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        // Checking for last occurence
        l = 0, r = n - 1;
        while(l <= r) {
            int m = (l + r)/ 2;
            if(a[m] == k) {
                hi = m;
                l = m + 1;
            }
            else if(a[m] > k) {
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        if(lo == -1 || hi == -1) {
            return 0;
        } 
        return (hi - lo + 1);
    }
    int searchRotated(vector<int> &a, int k) {
        int n = a.size(), l = 0, r = a.size() - 1;
        if(k == a[l]) return l;
        if(k == a[r]) return r;
        while(l <= r) {
            int m = (l + r) / 2;
            if(a[m] == k) {
                return m;
            }
            if(a[l] <= a[m]) {
                if(a[l] <= k && k <= a[m]) {
                    r = m - 1;
                }
                else {
                    l = m + 1;
                }
            }
            else {
                if(a[m] <= k && k <= a[r]) {
                    l = m + 1;
                }
                else {
                    r = m - 1;
                }
            }
        }
        return -1;
    }
    bool sRotated(vector<int> &a, int k) {
        int n = a.size();
        int l = 0, r = n - 1;
        if(a[l] == k) return true;
        if(a[r] == k) return true;
        while(l <= r) {
            int m = (l + r) / 2;
            if(a[m] == k) {
                return true;
            }
            if(a[l] == a[m] && a[m] == a[r]) {
                l++;
                r--;
                continue;
            }

            if(a[l] <= a[m]) {
                if(a[l] <= k && k <= a[m]) {
                    r = m - 1;
                }
                else {
                    l = m + 1;
                }
            }
            else {
                if(a[m] <= k && k <= a[r]) l = m + 1;
                else r = m - 1;
            }
        }      return false;
    }

    int findMin(vector<int> &a) {
        int n = a.size();
        int l = 0, r = n - 1, ans = INT_MAX;
        while(l <= r) {
            int m = (l + r) / 2;

            if(a[l] <= a[m]) {
                ans = min(a[l], ans);
                l = m + 1;
            }
            else {
                ans = min(ans, a[m]);
                r = m - 1;
            }

        }
        return ans; 
    }
    int findKrotation(vector<int> &a) {
        int n = a.size();
        int l = 0, r = n - 1, ans = INT_MAX;
        while(l <= r) {
            int m = (l + r) / 2;

            if(a[l] <= a[m]) {
                ans = min(a[l], ans);
                l = m + 1;
            }
            else {
                ans = min(ans, a[m]);
                r = m - 1;
            }

        }
        l = 0, r = n - 1;
        while(l <= r) {
            int m = (l + r) / 2;
            if(a[m] == ans) {
                return m;
            }
            else if(a[m] > ans) r = m - 1;
            else l = m + 1;
        }
    }
    int singleNonDuplicate(vector<int> &a) {
        int n = a.size();
        int l = 0, r = n - 1;
        while(l <= r) {
            int m = (l + r) / 2;

        }
    }

};


int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n ; i++) {
        cin >> a[i];
    }
    solution s;
    int res = s.findMin(a);
    cout << res <<'\n';
}
