/*
    Author: Dhruv Varshney
    Date - 2025/05/25
    Time - 08:25:05
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

struct node {
    int val;
    node* left;
    node* right;
    node(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
    private:
    void toLeaf(node* root, vi &a, vvi &res) {
        if(root == nullptr) {
            return;
        }
        a.push_back(root->val);
        if(!root->left && !root->right) {
            res.push_back(a);
        }
        else {
            toLeaf(root->left, a, res);
            toLeaf(root->right, a, res);
        }
        a.pop_back();
    }

    node* toRoot(node* root, node* p, node* q) {
        if(root == nullptr) return root;

        if(root == p || root == q) {
            return root;
        }                                                                     

        node* lft = toRoot(root->left, p, q);
        node* rt = toRoot(root->right, p, q);

        if(lft && rt) {
            return root;
        }

        if(lft) {
            return lft;
        }
        return rt;

    }
    public:
    vector<vector<int>> allRootToLeaf(node* root) {
        vvi res;
        if(root == nullptr) {
            return res;
        }
        vi a;
        toLeaf(root, a, res);
        return res;
    }

    node* lowestCommonAncestor(node* root, node* p, node* q) {
        return toRoot(root, p, q);
    }

    // Function to delete tree
    void deleteTree(node* root) {
        if(root == nullptr) return;

        deleteTree(root->left);
        deleteTree(root->right);

        delete root;
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    Solution sol;
    
    /* Test Case 1: Complete binary tree
           1
          / \
         2   3
        / \ / \
       4  5 6  7
    Find LCA of nodes 4 and 5
    */
    
    node* root1 = new node(1);
    root1->left = new node(2);
    root1->right = new node(3);
    root1->left->left = new node(4);
    root1->left->right = new node(5);
    root1->right->left = new node(6);
    root1->right->right = new node(7);
    
    node* lca1 = sol.lowestCommonAncestor(root1, root1->left->left, root1->right);
    cout << "Test Case 1 - LCA of 4 and 5: " << (lca1 ? lca1->val : -1) << '\n';
    sol.deleteTree(root1);
    
    /* Test Case 2: Single node
       10
    Find LCA of node with itself
    */
    
    node* root2 = new node(10);
    
    node* lca2 = sol.lowestCommonAncestor(root2, root2, root2);
    cout << "Test Case 2 - LCA of 10 and 10: " << (lca2 ? lca2->val : -1) << '\n';
    sol.deleteTree(root2);
    
    /* Test Case 3: Left skewed tree
       1
      /
     2
    /
   3
  /
 4
    Find LCA of nodes 1 and 4
    */
    
    node* root3 = new node(1);
    root3->left = new node(2);
    root3->left->left = new node(3);
    root3->left->left->left = new node(4);
    
    node* lca3 = sol.lowestCommonAncestor(root3, root3, root3->left->left->left);
    cout << "Test Case 3 - LCA of 1 and 4: " << (lca3 ? lca3->val : -1) << '\n';
    sol.deleteTree(root3);
    
    /* Test Case 4: Right skewed tree
       1
        \
         2
          \
           3
            \
             4
    Find LCA of nodes 2 and 4
    */
    
    node* root4 = new node(1);
    root4->right = new node(2);
    root4->right->right = new node(3);
    root4->right->right->right = new node(4);
    
    node* lca4 = sol.lowestCommonAncestor(root4, root4->right, root4->right->right->right);
    cout << "Test Case 4 - LCA of 2 and 4: " << (lca4 ? lca4->val : -1) << '\n';
    sol.deleteTree(root4);
    
    /* Test Case 5: Complex tree with overlapping nodes
            20
           /  \
          8    22
         / \   / \
        5   3 4   25
           / \
          10  14
    Find LCA of nodes 10 and 14
    */
    
    node* root5 = new node(20);
    root5->left = new node(8);
    root5->right = new node(22);
    root5->left->left = new node(5);
    root5->left->right = new node(3);
    root5->right->left = new node(4);
    root5->right->right = new node(25);
    root5->left->right->left = new node(10);
    root5->left->right->right = new node(14);
    
    node* lca5 = sol.lowestCommonAncestor(root5, root5->left->right->left, root5->left->right->right);
    cout << "Test Case 5 - LCA of 10 and 14: " << (lca5 ? lca5->val : -1) << '\n';
    
    // Additional test case for nodes in different subtrees
    node* lca5b = sol.lowestCommonAncestor(root5, root5->left->left, root5->right->right);
    cout << "Test Case 5b - LCA of 5 and 25: " << (lca5b ? lca5b->val : -1) << '\n';
    
    sol.deleteTree(root5);
    
    return 0;
}
