/*
    Author: Dhruv Varshney
    Date - 2025/06/02
    Time - 23:54:17
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

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data) {
        val = data;
        left = right = nullptr;
    }
};

class Solution {
    private:
    TreeNode* buildBST(vector<int> &pre,int lo, int hi) {
        if(lo > hi) return nullptr;
        TreeNode* root = new TreeNode(pre[lo]);
        int val = hi + 1;
        for(int i = lo + 1; i <= hi ; i++) {
            if(pre[i] > root->val) {
                val = i;
                break;
            }
        }

        root->left = buildBST(pre, lo + 1, val - 1);
        root->right = buildBST(pre,val, hi);

        return root;
    }
    public:
    TreeNode* bstFromPreorder(vector<int>& pre) {
        TreeNode* root = buildBST(pre,0, pre.size() - 1);
        return root;
    }
};

// Helper function to print preorder traversal of the tree.
void printPreorder(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

// Helper function to delete the tree and free memory.
void deleteTree(TreeNode* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

signed main() {
    Solution sol;

    // Test case 1
    vector<int> preorder1 = {8, 5, 1, 7, 10, 12};
    TreeNode* root1 = sol.bstFromPreorder(preorder1);
    printPreorder(root1);
    cout << endl;
    deleteTree(root1);

    // Test case 2
    vector<int> preorder2 = {1};
    TreeNode* root2 = sol.bstFromPreorder(preorder2);
    printPreorder(root2);
    cout << endl;
    deleteTree(root2);

    // Test case 3
    vector<int> preorder3 = {5, 3, 2, 4, 8, 7, 9};
    TreeNode* root3 = sol.bstFromPreorder(preorder3);
    printPreorder(root3);
    cout << endl;
    deleteTree(root3);

    // Test case 4
    vector<int> preorder4 = {10, 5, 1, 7, 40, 50};
    TreeNode* root4 = sol.bstFromPreorder(preorder4);
    printPreorder(root4);
    cout << endl;
    deleteTree(root4);

    // Test case 5
    vector<int> preorder5 = {2, 1, 3};
    TreeNode* root5 = sol.bstFromPreorder(preorder5);
    printPreorder(root5);
    cout << endl;
    deleteTree(root5);

    return 0;
}