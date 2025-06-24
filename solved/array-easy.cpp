# include <bits/stdc++.h>
using namespace std;
# define int long long
const int mod = (7 + 1e9);

typedef vector<int> vi;
typedef set<int> si;

class Solution {
public:
    int getSecondLargest(vector<int> &a) {
        int n = a.size();
        int max1 = INT_MIN, max2 = INT_MIN, i = 0;
        if(n == 0 || n == 1) return -1;
        for(i = 0; i < n; i++) {
            if(a[i] > max1) {
                max2 = max1;
                max1 = a[i];
            }
            else if(a[i] > max2 && a[i]!=max1) {
                max2 = a[i];
            }
        }
        if(max2 == INT_MIN) {
            return -1;
        }
        return max2;
    }

    bool isSorted(vector<int> &a) {
        int n = a.size(), count = 0;
        for(int i = 0; i < n - 1; i++) {
            if(a[i] > a[i + 1]) {
                count++;
            }
        }
        if(count == 0) return true;
        if(count == 1 && a[n - 1] < a[0]) return true;
        else return false;
    }

    int removeDuplicates(vector<int>& a) {
        int n = a.size(),j = 0;
        for(int i = 0; i < n - 1; i++) {
            if(a[i] != a[i + 1]) {
                j++;
                a[j] = a[i + 1];
            }
        }
        return j + 1;
    }
    // Solution with time complexity = O(n*k)
    void rightRotate(vector<int>& a, int k) {

        int n = a.size();

        if(k > n) {
            k %= n;
        }
        for(int j = 0; j < k; j++) {
            int t = a[n - 1];
            for(int i = n - 1; i >= 0; i--) {
                a[i + 1] = a[i];
            }
            a[0] = t;
        }
    }

    // Solution with time complexity = O(n)
    void rotate(vector<int>& a, int k) {

        int n = a.size();

        if(k > n) {
            k %= n;
        }

        vector<int> temp(k, 0);
        for(int i = 0; i < k ; i++) {
            temp[i] = a[n - i - 1];
        }

        for(int i = n - 1; i >= k ; i --) {
            a[i] = a[i - k];
        }
        for(int i = 0; i < k ; i++) {
            a[i] = temp[k - i];
        }
    }
    
    void moveZeroes(vector<int> &a) {
        int n = a.size();

        vector<int> temp;

        for(int i = 0; i < n; i++) {
            if(a[i] != 0) {
                temp.push_back(a[i]);
            }
        }

        for(int i = 0; i < n; i++) {
            if(i < temp.size()) {
                a[i] = temp[i];
            }
            else {
                a[i] = 0;
            }
        }
    }

    bool searchInSorted(vector<int> &a, int x) {
        int k = 0, n = a.size();
        for(int r = (n / 2); r >= 1 ; r /= 2) {
            while(k + r < n && a[k + r] <= k) k += r;
        }
        if(a[k] == x) return true;
        return false; 
    }
    

    vector<int> Union(vector<int> &a, vector<int> &b) {
        int n = a.size(), m = b.size();

        vector<int> un(n + m);
        vector<int>::iterator it;

        it = set_union(a.begin(), a.end(), b.begin(), b.end(), un.begin());
        un.resize(it - un.begin());
        return un;
    }

    vector<int> findUnion1(vi &a, vi &b) {
        map<int, int> hsh;
        vector<int> res;
        for(int i = 0; i < a.size(); i++) {
            hsh[a[i]]++;
        }
        for(int i = 0; i < b.size(); i++) {
            hsh[b[i]]++;
        }
        for(auto &x : hsh) {
            res.push_back(x.first);
        }
        return res;
    }
    
    vi findUnion2(vi &a, vi &b) {
        set<int> s;
        vi res;
        for(int x : a) s.insert(x);
        for(int y : b) s.insert(y);
        for(int z : s) res.push_back(z);
    
        return res;
    }
    
    vi findUnion(vi &a, vi &b) {
        // For sorted arrays only
        vi un;
        int i = 0, j = 0;
        while(i < a.size() && j < b.size()) {
            if(a[i] <= b[j]) {
                if(un.empty() || un.back() != a[i]) un.push_back(a[i]);
                i++;
            }
            else {
                if(un.empty() || un.back() != b[j]) un.push_back(b[j]);
                j++;
            }
        }
        while(i < a.size()) {
            if(un.back() != a[i])
                un.push_back(a[i]);
            i++;
        }
        while(j < b.size()) {
            if(un.back() != b[j])
                un.push_back(b[j]);
            j++;
        }
        return un;
    }

    int missingNumber(vector<int> &nums) {
        int n = nums.size(), sum = 0;
        for(int i = 0; i < n ; i++) {
            sum += nums[i];
        }
        return (n*(n + 1) / 2 - sum);
    }

    int singleNumber(vector<int> &a) {
        int n = a.size();
        int res = 0;
        for(int i = 0; i < n; i++) {
            res ^= a[i];
        }
        return res;
    }

    // Time Complexity: O(n^2)
    
    int longestSubarray(vector<int> &a, int k) {
        int n = a.size(),len, m = 0;
        for(int i = 0; i < n; i++) {
            int sum = 0;
            for(int j = i; j < n; j++) {
                sum += a[j];
                if(sum == k) {
                    len = j - i + 1;
                }
            }
            m = max(len, m);
        }
        return m;
    }

    int maxsubarray(vector<int> &a, int k) {
        int n = a.size();
        map<int, int> hsh;
        int sum = 0, m = INT_MIN;
        for(int i = 0; i < n; i++) {
            sum += a[i];
            if(sum == k) hsh[sum] = i;
            else if(hsh.find(sum - k)!= hsh.end()) {
                m = max(m, i - hsh[sum - k]);
            }
            if(sum == 0) hsh[sum] = i;
        }
            
    }
};

int32_t main() {
    Solution s;
    vector<int> a = {10, 5, 2, 7, 1, -10};
    cout << s.longestSubarray(a, 15);
    return 0;
}