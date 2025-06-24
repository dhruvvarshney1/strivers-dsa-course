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

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    
    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }  
};

class Solution {
    private:
    TreeNode* treeBuild(vector<int>& in, int inStart, int inEnd, vector<int>& post, int postStart, int postEnd, map<int, int> &inMap) {
        if(inStart > inEnd || postStart > postEnd) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(post[postEnd]);
        int inRoot = inMap[root->val];
        int numLeft = inRoot - inStart;
        
        root->left = treeBuild(in, inStart, inRoot - 1, post, postStart, postStart + numLeft - 1, inMap);

        root->right = treeBuild(in, inRoot + 1, inEnd, post, postStart + numLeft, postEnd - 1, inMap);

        return root;
    }
    public:
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        map<int, int> inMap;
        for(int i = 0;i < in.size();i++) {
            inMap[in[i]] = i;
        }
        TreeNode* root = treeBuild(in, 0, in.size() - 1, post, 0, post.size() - 1, inMap);
        return root;
    }
};

