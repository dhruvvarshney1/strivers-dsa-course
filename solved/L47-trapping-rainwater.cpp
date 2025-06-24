# include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
    int trap(vector<int> &h) {
        int n=h.size();
        if(!n) return 0;
        
    }

    int trap_suboptimal(vector<int> &h) {
        int n = h.size();
        if(n == 0) return 0;

        // Prefix Max loop
        vector<int> prefixMax(n);
        prefixMax[0] = h[0];
        for(int i = 1; i < n ; i++) {
            prefixMax[i] = max(prefixMax[i-1], h[i]);
        }

        // Suffix Max loop
        vector<int> suffixMax(n);
        suffixMax[n-1] = h[n-1];
        for(int i = n-2; i >= 0 ; i--) {
            suffixMax[i] = max(suffixMax[i+1], h[i]);
        }

        int waterTrapped = 0;
        for(int i = 0; i < n ; i++) {
            (h[i] < prefixMax[i] && h[i] < suffixMax[i])?(waterTrapped += min(prefixMax[i], suffixMax[i]) - h[i]) : NULL;
        }
        return waterTrapped;
    }
};