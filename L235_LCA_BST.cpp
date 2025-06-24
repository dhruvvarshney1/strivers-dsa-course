/*
    Author: Dhruv Varshney
    Date - 2025/06/02
    Time - 22:30:43
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
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
    public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) {
            return nullptr;
        }

        TreeNode* tem = root;

        while(tem != nullptr) {
            int p_val = p->val, q_val = q->val;

            int tem_val = tem->val;

            if(p_val < tem_val && q_val < tem_val) {
                tem = tem->left;
            }
            else if(p_val > tem_val && q_val > tem_val) {
                tem = tem->right;
            }
            else {
                return tem;
            }
        }

        return nullptr;
    }
};
// Helper function to find a TreeNode by its value in the BST.
// Assumes TreeNode with targetVal exists in the tree, and all values are unique.
TreeNode* findNodeByVal(TreeNode* root, int targetVal) {
    TreeNode* current = root;
    while (current != nullptr) {
        if (targetVal < current->val) {
            current = current->left;
        } else if (targetVal > current->val) {
            current = current->right;
        } else { // targetVal == current->val
            return current;
        }
    }
    return nullptr; // Should not be reached if TreeNode is guaranteed to be in the tree
}

// Helper function to deallocate tree memory (important for local testing).
void deleteTree(TreeNode* root) {
    if (!root) {
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

signed main() {
    // Optimize C++ streams for faster I/O if needed for very large number of test cases,
    // but for a few illustrative cases, it's not critical.
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(NULL);

    Solution sol;
    TreeNode *root = nullptr;
    TreeNode *p_node = nullptr;
    TreeNode *q_node = nullptr;
    TreeNode *lca_node = nullptr;

    // Test Case 1: General case
    // Tree: [6,2,8,0,4,7,9,null,null,3,5], p=2, q=8. Expected LCA: 6
    root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    
    p_node = findNodeByVal(root, 2);
    q_node = findNodeByVal(root, 8);
    lca_node = sol.lowestCommonAncestor(root, p_node, q_node);
    if (lca_node) { // Check to be safe, though problem guarantees LCA exists
        std::cout << lca_node->val << std::endl;
    }
    deleteTree(root);

    // Test Case 2: One TreeNode is an ancestor of the other
    // Tree: [6,2,8,0,4,7,9,null,null,3,5], p=2, q=4. Expected LCA: 2
    root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    p_node = findNodeByVal(root, 2);
    q_node = findNodeByVal(root, 4);
    lca_node = sol.lowestCommonAncestor(root, p_node, q_node);
    if (lca_node) {
        std::cout << lca_node->val << std::endl;
    }
    deleteTree(root);

    // Test Case 3: Small tree, one TreeNode is root
    // Tree: [2,1], p=2, q=1. Expected LCA: 2
    root = new TreeNode(2);
    root->left = new TreeNode(1);

    p_node = findNodeByVal(root, 2);
    q_node = findNodeByVal(root, 1);
    lca_node = sol.lowestCommonAncestor(root, p_node, q_node);
    if (lca_node) {
        std::cout << lca_node->val << std::endl;
    }
    deleteTree(root);

    // Test Case 4: Nodes in different branches, more complex structure
    // Tree: [3,1,4,null,2], p=2, q=4. Expected LCA: 3
    //   3
    //  / \
    // 1   4
    //  \
    //   2
    root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);

    p_node = findNodeByVal(root, 2); 
    q_node = findNodeByVal(root, 4);
    lca_node = sol.lowestCommonAncestor(root, p_node, q_node);
    if (lca_node) {
        std::cout << lca_node->val << std::endl;
    }
    deleteTree(root);

    // Test Case 5: Nodes deeper in the same subtree
    // Tree: [6,2,8,0,4,7,9,null,null,3,5], p=3, q=5. Expected LCA: 4
    root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    p_node = findNodeByVal(root, 3);
    q_node = findNodeByVal(root, 5);
    lca_node = sol.lowestCommonAncestor(root, p_node, q_node);
    if (lca_node) {
        std::cout << lca_node->val << std::endl;
    }
    deleteTree(root);
    
    // Test Case 6: Nodes are min and max of a large subtree
    // Tree: [20,10,30,5,15,25,35,null,7,12,null,null,27], p=7, q=12. Expected LCA: 10
    //         20
    //        /  \
    //       10   30
    //      / \   / \
    //     5  15 25 35
    //      \ /    \
    //       7 12   27
    root = new TreeNode(20);
    root->left = new TreeNode(10);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(15);
    root->right->left = new TreeNode(25);
    root->right->right = new TreeNode(35);
    root->left->left->right = new TreeNode(7);
    root->left->right->left = new TreeNode(12);
    root->right->left->right = new TreeNode(27);

    p_node = findNodeByVal(root, 7);
    q_node = findNodeByVal(root, 12);
    lca_node = sol.lowestCommonAncestor(root, p_node, q_node);
    if (lca_node) {
        std::cout << lca_node->val << std::endl;
    }
    deleteTree(root);

    // Test Case 7: Nodes far apart, LCA is root
    // Tree from TC6, p=5, q=35. Expected LCA: 20
    root = new TreeNode(20);
    root->left = new TreeNode(10);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(15);
    root->right->left = new TreeNode(25);
    root->right->right = new TreeNode(35);
    root->left->left->right = new TreeNode(7);
    root->left->right->left = new TreeNode(12);
    root->right->left->right = new TreeNode(27);

    p_node = findNodeByVal(root, 5);
    q_node = findNodeByVal(root, 35);
    lca_node = sol.lowestCommonAncestor(root, p_node, q_node);
    if (lca_node) {
        std::cout << lca_node->val << std::endl;
    }
    deleteTree(root);


    return 0;
}