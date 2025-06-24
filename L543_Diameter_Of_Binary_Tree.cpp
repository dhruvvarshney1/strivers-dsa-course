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
    int maxH(node* root, int &h) {

        if(root == nullptr)  return 0;

        int lh = maxH(root->left, h);
        int rh = maxH(root->right, h);

        h = max(lh + rh, h);

        return 1 + max(lh, rh);
    }
public:
    int diameterBT(node* root) {
        if(root == nullptr) return 0;

        int h = 0;
        maxH(root, h);

        return h;
    }
};

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
        cout << sol.diameterBT(root) << '\n';
        
        deleteTree(root);

    }
    return 0;
}
