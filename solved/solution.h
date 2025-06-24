# include <bits/stdc++.h>

using namespace std;

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
    };