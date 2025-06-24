/*
    Author: Dhruv Varshney
    Date - 2025/05/29
    Time - 10:28:53
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
    public:
    node* deleteNode(node* root, int k) {
        node* tem = root;

        while(tem != root) {
            if(k > tem->val) {
                tem = tem->right;
            }
            else {
                tem = tem->left;
            }
        }
    }
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Solution sol;
    
    // Create a simple BST:
    //       10
    //      /  \
    //     5    15
    //    / \     \

    
    //   3   7    20
    
    node* root = new node(10);
    root->left = new node(5);
    root->right = new node(15);
    root->left->left = new node(3);
    root->left->right = new node(7);
    root->right->right = new node(20);

    cout << sol.minBST(root) << endl;
    
    return 0;
}
