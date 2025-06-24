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
    int pathSum(node* root, int &k) {
        if(root == nullptr) {
            return 0;
        }

        int lmax = pathSum(root->left, k);
        int rmax = pathSum(root->right, k);

        lmax = max(0LL, lmax);
        rmax = max(0LL, rmax);

        k = max(k, root->val + lmax + rmax);

        return root->val + max(lmax, rmax);
    }
public:
    int maxPathSum(node* root) {
        if(root == nullptr) {
            return 0;
        }
        int k = INT_MIN;
        pathSum(root, k);

        return k;
    }

};

// Function to delete root
void deleteTree(node* root) {
        if(root == nullptr) {
            return;
        }
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _t = 1;
    //cin >> _t;
    while (_t--) {

        node* root = new node(1);
        root->left = new node(2);
        root->right = new node(3);
        root->left->left = new node(4);
        root->left->right = new node(5);
        root->right->left = new node(6);
        root->right->right = new node(7);

        Solution sol;
        cout << sol.maxPathSum(root) << '\n';
        
        deleteTree(root);

    }
    return 0;
}

