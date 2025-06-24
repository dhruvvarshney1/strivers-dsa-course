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
    struct node *left;
    struct node *right;
    
    node(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }  
};

class Solution {
    private:
    void dfs(node* root, int &c) {
        if(!root) {
            return;
        }
        c++;
        if(root->left) {
            dfs(root->left,c);
        }

        if(root->right) {
            dfs(root->right,c);
        }
    }
    public:
    int countNodes(node* root) {
        if(root == nullptr) {
            return 0;
        }

        int c = 0;
        dfs(root, c);
        return c;
    }
};

// Test function
signed main() {
    Solution sol;
    
    // Test Case 1: Tree [1,2,3,4,5,6]
    node* root1 = new node(1);
    root1->left = new node(2);
    root1->right = new node(3);
    root1->left->left = new node(4);
    root1->left->right = new node(5);
    root1->right->left = new node(6);
    
    cout << sol.countNodes(root1) << endl;  // Should output 6
    
    // Test Case 2: Empty tree
    node* root2 = nullptr;
    cout << sol.countNodes(root2) << endl;  // Should output 0
    
    // Test Case 3: Single node
    node* root3 = new node(1);
    cout << sol.countNodes(root3) << endl;  // Should output 1
    
    // Clean up
    delete root1->left->left;
    delete root1->left->right;
    delete root1->right->left;
    delete root1->left;
    delete root1->right;
    delete root1;
    delete root3;
    
    return 0;
}