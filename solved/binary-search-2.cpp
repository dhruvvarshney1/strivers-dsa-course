# include<bits/stdc++.h>

using namespace std;

# define int long long

const int mod = 7 + 1e9;

class optimal {
    public:
    int floorSqrt(int n) {
        // Method 1
        // return floor(sqrt(n))s;

        // Method 2
        int l = 1, r = n,ans;
        while(l <= r) {
            int m = (l + r) / 2;
            if(m*m <= n) {
                ans = m;
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }
        return ans;
    }
    int nthRoot(int k, int n) {
        int l = 1, r = n;
        while(l <= r) {
            int m = (l + r) / 2, val = 1;
            for(int i = 1; i <= k; i++) {
                val *= m;
                if(val > n) break;
                // cout << val << endl;
            }
            if(val == n) return m;
            else if(val < n) l = m + 1;
            else r = m - 1;
        }
        return -1;
    }
    // Leetcode 1539: Kth Missing Positive Number
    int findKthPositive(vector<int> &a, int k) {
        int n = a.size();
        if(k < a[0]) return k;
        int l = 0, r = n - 1;
        while(l <= r) {
            int mid = (l + r) / 2;
            if((a[mid] - (mid + 1)) < k) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }

        }
        return k + r + 1;
    }
    // Problem : Aggressive
    bool cowPlacement(vector<int> &a, int k, int m) {
        int n = a.size(), c = 1;
        int last = a[0];
        for(int i = 1; i < n ; i++) {
            if(a[i] - last >= m) {
                c++;
                last = a[i];
            }
            if(c >= k) return true;
        }
        return false;
    }
    int aggressiveCows(vector<int> &a, int k) {
        int n = a.size();
        sort(a.begin(), a.end());
        int l = 1, r = a[n - 1] - a[0];
        while(l <= r) {
            int m = (l + r) / 2;
            if(cowPlacement(a, k, m) == true) l = m + 1;
            else r = m - 1;
        }
        return r;
    }
    // Problem : Allocate Pages

};

class intution {
    public:

    int flsqrt(int n) {
        int ans;
        for(int i = 1; i <= (n / 2) ; i++) {
            if(i*i <= n) {
                ans = i;
            }
        }
        return ans;
    }
    int calcHours(vector<int> &a, int k) {
        int h = 0;
        for(int i = 0; i < a.size() ; i++) {
            h += ceil((double)a[i] / (double)k);
        }
        return h;
    }
    int minEatingSpeed(vector<int> &a, int h) {
        int max_val = INT_MIN;
        for(int i = 0; i < a.size() ; i++) {
            max_val = max(a[i], max_val);
        }
        int l = 1, r = max_val;
        while(l <= r) {
            int m = (l + r) / 2, th = calcHours(a, m);
            if(th <= h) {
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        return l;
    }

    // Leetcode 1482: Minimum Number of Days to Make m Bouqets

    bool task(vector<int> &a, int d, int m, int k) {
        int c = 0, nb = 0;
        for(int i = 0; i < a.size(); i++) {
            if(a[i] <= d) {
                c++;
            }
            else{
                nb += (c / k);
                c = 0;
            }
        }
        nb += (c / k);
        if(nb >= m) {
            return true;
        }
        else {
            return false;
        }
    }
    int minDays(vector<int> &a, int m , int k) {
        // No. of flowers required exceed the no. of flowers in the garden.
        if(a.size() < m*k) {
            return -1;
        }
        int hi = INT_MIN, lo = INT_MAX;
        for(int i = 0; i < a.size(); i++) {
            hi = max(a[i], hi);
            lo = min(a[i], lo);
        }
        // cout << hi << ' ' << lo << '\n';
        while(lo <= hi) {
            int mid = (lo + hi) / 2;
            if(task(a, mid, m, k)) {
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }
        }
        return lo;
    }

    // Leetcode 1283: Find the smallest divisor given a threshold

    int sumRem(vector<int> &a, int d) {
        int ans = 0;
        for(int x : a) {
            ans += ceil((double)x / (double)d);
        }
        return ans;
    }
    int smallestDivisor(vector<int> &a, int th) {
        int n = a.size(),lo = 1, hi = INT_MIN;
        for(int i = 0; i < n ; i++) {
            hi = max(a[i], hi);
        }
        while(lo <= hi) {
            int mid = (lo + hi) / 2;
            if(sumRem(a, mid) <= th) {
                hi = mid - 1;;
            }
            else lo = mid + 1;
        }
        return lo;
    }

    // Leetcode 1011: Capacity to Ship Packages within D days
    
    int packDays(vector<int> &a, int cap, int d) {
        int c = 1, sum = 0; 
        for(int i = 0; i < a.size() ; i++) {
            if(sum <= cap) {
                sum += a[i];
            }
            else {
                c++;
            }
        }
        // cout << c << ' ' << cap << endl;
        return (c <= d);
    }
    int shipWithinDays(vector<int> &w, int d) {
        int lo = *max_element(w.begin(), w.end()), hi = accumulate(w.begin(), w.end(), 0);
        for(int i = 0; i < w.size() ; i++) {
            hi += w[i];
        }
        while(lo <= hi) {
            int mid = (lo + hi) / 2;
            if(packDays(w, mid, d)) {
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        return lo;
    }

    // Leetcode 1539: Kth Missing Positive Number

    int findKthPositive(vector<int> &a, int k) {
        if(k < a[0]) {
            return k;
        }
        for(int i = 0; i < a.size() ; i++) {
            if(a[i] <= k) k++;
            else break;
        }
        return k;
    }
     
    // Problem: Aggresive Cows

    bool cowPlacement(vector<int> &a, int k, int m) {
        int n = a.size(), c = 1;
        int last = a[0];
        for(int i = 1; i < n ; i++) {
            if(a[i] - last >= m) {
                c++;
                last = a[i];
            }
            if(c >= k) return true;
        }
        return false;
    }
    int aggressiveCows(vector<int> &a, int k) {

        // Brute Force Solution
        int n = a.size(), i = 0;
        sort(a.begin(), a.end());
        int lim = a[n - 1] - a[0];
        for(i = 1; i <= lim ; i++) {
            if(cowPlacement(a, k, i) == false) {
                return (i - 1);
            }
        }
        return lim;
    } 
    
    // Problem: Allocate Pages

    int pageDistribution(vector<int> &a, int )

    int findPages(vector<int> &a, int m) {
        int n = a.size();
        if(m > n) {
            return -1;
        }
        for(int i = 0; i < n ; i++) {
            int s1 = 0, s2 = 0, ans, min_Max, max_val;
            for(int j = 0; j < i ; j++) {
                s1 += a[j];
            }
            for(int j = i + 1; j < n ; j++) {
                s2 += a[j];
            }
        }        
    }
};

int32_t main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n); 
    for(int i = 0; i < n ; i++) {
        cin >> a[i];
    }
    intution it;
    optimal op;
    cout << it.findPages(a, k);
}