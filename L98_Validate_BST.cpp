/*
    Author: Dhruv Varshney
    Date - 2025/05/31
    Time - 00:53:12
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
    
    TreeNode(int data) : val(data), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    bool inInterval(TreeNode* root, long long lx, long long rx) {

        if(!root) {
            return true;
        }

        if(lx >= root->val || rx <= root->val) {
            return false;
        }

        return inInterval(root->left, lx, root->val) && inInterval(root->right, root->val, rx);
    }
public:
    bool isValidBST(TreeNode* root) {
        long long lx = LLONG_MIN;
        long long rx = LLONG_MAX;
        bool ans = inInterval(root, lx, rx);
        return ans;
    }
};

// Helper function to deallocate tree memory.
// This function does not produce any console output.
void deleteTree(TreeNode* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

signed main() {
    // Optimize C++ streams and print booleans as "true"/"false".
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << boolalpha; 

    Solution sol;

    // Test Case 1: Empty tree
    TreeNode* tc1_root = nullptr;
    cout << sol.isValidBST(tc1_root) << endl;

    // Test Case 2: Single TreeNode tree
    TreeNode* tc2_root = new TreeNode(10);
    cout << sol.isValidBST(tc2_root) << endl;
    deleteTree(tc2_root);

    // Test Case 3: Simple tree that is a valid BST by standard definition
    //   2
    //  / \
    // 1   3
    TreeNode* tc3_root = new TreeNode(2);
    tc3_root->left = new TreeNode(1);
    tc3_root->right = new TreeNode(3);
    cout << sol.isValidBST(tc3_root) << endl;
    deleteTree(tc3_root);

    // Test Case 4: Invalid BST - left child greater than root
    //   1
    //  /
    // 2
    TreeNode* tc4_root = new TreeNode(1);
    tc4_root->left = new TreeNode(2);
    cout << sol.isValidBST(tc4_root) << endl;
    deleteTree(tc4_root);

    // Test Case 5: Invalid BST - right child smaller than root
    //   3
    //    \
    //     2
    TreeNode* tc5_root = new TreeNode(3);
    tc5_root->right = new TreeNode(2);
    cout << sol.isValidBST(tc5_root) << endl;
    deleteTree(tc5_root);

    // Test Case 6: More complex tree, valid BST by standard definition
    //     5
    //    / \
    //   3   7
    //  / \ / \
    // 2  4 6  8
    TreeNode* tc6_root = new TreeNode(5);
    tc6_root->left = new TreeNode(3);
    tc6_root->right = new TreeNode(7);
    tc6_root->left->left = new TreeNode(2);
    tc6_root->left->right = new TreeNode(4);
    tc6_root->right->left = new TreeNode(6);
    tc6_root->right->right = new TreeNode(8);
    cout << sol.isValidBST(tc6_root) << endl;
    deleteTree(tc6_root);

    // Test Case 7: Invalid BST - grandparent constraint violation (LeetCode example: [5,1,4,null,null,3,6])
    //     5
    //    / \
    //   1   4  <-- TreeNode 4's value is problematic.
    //      / \
    //     3   6
    TreeNode* tc7_root = new TreeNode(5);
    tc7_root->left = new TreeNode(1);
    tc7_root->right = new TreeNode(4);
    if (tc7_root->right) { // Check added for safety, though TreeNode(4) is just created
        tc7_root->right->left = new TreeNode(3);
        tc7_root->right->right = new TreeNode(6);
    }
    cout << sol.isValidBST(tc7_root) << endl;
    deleteTree(tc7_root);
    
    // Test Case 8: Tree with LLONG_MIN and LLONG_MAX values
    //   0
    //  / \
    //LLONG_MIN LLONG_MAX
    TreeNode* tc8_root = new TreeNode(0); // Using 0 as int is long long
    tc8_root->left = new TreeNode(LLONG_MIN); 
    tc8_root->right = new TreeNode(LLONG_MAX); 
    cout << sol.isValidBST(tc8_root) << endl;
    deleteTree(tc8_root);

    // Test Case 9: Root is LLONG_MAX, left child exists
    //   LLONG_MAX
    //  /
    // 0
    TreeNode* tc9_root = new TreeNode(LLONG_MAX);
    tc9_root->left = new TreeNode(0);
    cout << sol.isValidBST(tc9_root) << endl;
    deleteTree(tc9_root);

    // Test Case 10: Root is LLONG_MIN, right child exists
    //   LLONG_MIN
    //     \
    //      0
    TreeNode* tc10_root = new TreeNode(LLONG_MIN);
    tc10_root->right = new TreeNode(0);
    cout << sol.isValidBST(tc10_root) << endl;
    deleteTree(tc10_root);

    // Test Case 11: Another complex invalid BST (LeetCode example: [3,1,5,0,2,4,6,null,null,null,3])
    // TreeNode 2 has right child 3.
    //          3
    //        /   \
    //       1     5
    //      / \   / \
    //     0   2 4   6
    //          \
    //           3  <-- This TreeNode 3 is problematic.
    TreeNode* tc11_root = new TreeNode(3);
    tc11_root->left = new TreeNode(1);
    tc11_root->left->left = new TreeNode(0);
    tc11_root->left->right = new TreeNode(2);
    tc11_root->left->right->right = new TreeNode(3); 
    tc11_root->right = new TreeNode(5);
    tc11_root->right->left = new TreeNode(4);
    tc11_root->right->right = new TreeNode(6);
    cout << sol.isValidBST(tc11_root) << endl; 
    deleteTree(tc11_root);

    return 0;
}
