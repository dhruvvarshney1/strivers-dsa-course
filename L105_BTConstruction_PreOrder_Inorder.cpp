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
    TreeNode* treeBuild(vector<int>& pre, int preStart, int preEnd, vector<int>& in, int inStart, int inEnd, map<int, int> &inMap) {
        if(preStart > preEnd || inStart > inEnd) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(pre[preStart]);
        int inRoot = inMap[root->val];
        int numLeft = inRoot - inStart;
        root->left = treeBuild(pre, preStart + 1, preStart + numLeft, in, inStart, inRoot - 1, inMap);
        root->right = treeBuild(pre, preStart + numLeft + 1, preEnd, in, inRoot + 1, inEnd, inMap);
    }
    public:
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        map<int, int> inMap;
        for(int i = 0;i < in.size();i++) {
            inMap[inMap[i]] = i;
        }
        TreeNode* root = treeBuild(pre, 0, pre.size() - 1, in, 0, in.size() - 1, inMap);
        return root;
    }

    void deleteTree(TreeNode* root) {
        if(root == nullptr) {
            return;
        }
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
};


// Helper function to find a TreeNode with given value
TreeNode* findTreeNode(TreeNode* root, int val) {
    if(!root) return nullptr;
    if(root->val == val) return root;
    
    TreeNode* left = findTreeNode(root->left, val);
    if(left) return left;
    
    return findTreeNode(root->right, val);
}

