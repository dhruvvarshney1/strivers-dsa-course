/*
    Author: Dhruv Varshney
    Date - 2025/06/26
    Time - 10:04:16
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

class Solution {
    public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());

        queue<pair<string, int>> q;

        q.push({beginWord, 1});

        while(!q.empty()) {
            string word = q.front().first;
            int step = q.front().second;
            q.pop();

            if(word == endWord) {
                return step;
            }

            for(int i = 0; i < word.size(); i++) {
                
                char og = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    if(st.find(word) != st.end()) {
                        st.erase(word);
                        q.push({word, step+1});
                    }
                }
                word[i] = og;
            }
        }
        return 0;
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