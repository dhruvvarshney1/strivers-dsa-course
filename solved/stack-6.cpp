# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& a, vector<int>& b) {
        unordered_map<int, int> ans;
        stack<int> st;

        for(int i = b.size() - 1; i >= 0; i--) {

            while(!st.empty() && st.top() <= b[i]) {
                st.pop();
            }

            if(st.empty()) ans[b[i]] = -1;
            else ans[b[i]] = st.top();

            st.push(b[i]);
        }

        vector<int> res(a.size());
        for(int i = 0; i < a.size() ; i++) {
            res[i] = ans[a[i]];
        }

        return res;
    }
    vector<int> nextGreaterElements(vector<int>& a) {
        stack<int> st;
        vector<int> res(a.size(), -1);
        for(int i = 2*a.size() - 1; i >= 0 ; i--) {
            while(!st.empty() && a[i % a.size()] >= st.top()) {
                st.pop();
            }
            if (i < a.size()) {
                if (!st.empty()) res[i] = st.top();
            }
            st.push(a[i % a.size()]);
        }
        return res;
    }
    vector<int> prevSmaller(vector<int>& a) {
        int n = a.size();
    
        stack<int> s;
        vector<int> g;
    
        for(int i = 0; i < n ; i++) {
            while(!s.empty() && s.top() >= a[i]) {
                s.pop();
            }
            if(s.empty()) g.push_back(-1);
            else g.push_back(s.top());
    
            s.push(a[i]);
        }
    
        return g;
    }
    vector<int> count_NGE(int n, vector<int> &a, int q, vector<int>& idx) {
        vector<int> ans; // To store answers for each query
        
        // Find the maximum value in the array to size BIT appropriately.
        int maxValue = *max_element(a.begin(), a.end());
        
        // res will store the count of elements greater than a[i] to its right.
        vector<int> res(n, 0);
        // BIT array is 1-indexed, so we create an array of size maxValue+2.
        vector<int> BIT(maxValue + 2, 0);
        
        // Lambda function to update the BIT.
        auto update = [&](int index, int val) {
            for(; index < BIT.size(); index += index & -index) {
                BIT[index] += val;
            }
        };
        
        // Lambda function to query the BIT.
        auto queryBIT = [&](int index) -> int {
            int sum = 0;
            for(; index > 0; index -= index & -index) {
                sum += BIT[index];
            }
            return sum;
        };
        
        // Process the array from right to left.
        // For each position, the query BIT gathers count of numbers that are greater than a[i].
        for (int i = n - 1; i >= 0; i--) {
            int value = a[i];
            // BIT is 1-indexed; query for elements with value greater than 'value'.
            int countGreater = queryBIT(maxValue + 1) - queryBIT(value);
            res[i] = countGreater;
            // Update BIT for the current element.
            update(value, 1);
        }
        
        // For each query index, collect the precomputed result.
        for (int i = 0; i < q; i++) {
            int queryIndex = idx[i];
            ans.push_back(res[queryIndex]);
        }
        
        return ans;
    }
};
