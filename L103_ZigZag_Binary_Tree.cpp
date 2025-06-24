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
public:
    vector<vector<int>> zigzagLevelOrder(node* root) {
        vector<vector<int>> res;
        if(root == nullptr) return res;

        queue<node*> q;

        q.push(root);
        bool rev = 0;
        while(!q.empty()) {
            int n = q.size();
            vector<int> a(n);
            for(int i = 0; i < n ;i++) {
                node* tem = q.front();
                q.pop();
                if(rev) {
                    a[n - i -1] = tem->val;
                }
                else {
                    a[i] = tem->val;
                }
                if(tem->left) q.push(tem->left);
                if(tem->right) q.push(tem->right);
            }
            res.push_back(a);
            rev = !rev;
        }
        return res;
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

        node* p = new node(1);
        p->left = new node(2);
        p->right = new node(3);
        p->left->left = new node(4);
        p->left->right = new node(5);
        p->right->left = new node(6);
        p->right->right = new node(7);

        node* q = new node(1);
        q->left = new node(2);
        q->right = new node(3);
        q->left->left = new node(4);
        q->left->right = new node(5);
        q->right->left = new node(6);
        q->right->right = new node(7);

        Solution sol;
        vvi res = sol.zigzagLevelOrder(p);

        for(auto &x : res) {
            for(int y : x) {
                cout << y <<' ';
            }
            cout << '\n';
        }
        
        deleteTree(p);
        deleteTree(q);

    }
    return 0;
}

