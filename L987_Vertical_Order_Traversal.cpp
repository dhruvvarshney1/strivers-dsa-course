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
    void vertGo(node* root, int col, map<int, multiset<int>> &mp) {
        if(root == nullptr) return;
        mp[col].insert(root->val);
        vertGo(root->left, col-1, mp);
        vertGo(root->right, col+1, mp);

    }
public:
    vector<vector<int>> verticalTraversal(node* root) {
        vector<vector<int>> res;
        if(root == nullptr) return res;

        map<int, multiset<int>> mp;
        int col = 0;
        vertGo(root, 0, mp);

        for(auto& p : mp) {
            res.push_back(vector(p.second.begin(), p.second.end()));
        }
        return res;
    }

// private:
//     void vertGo(node* root, int row, int col, map<int, map<int, multiset<int>>>& mp) {
//         if(root == nullptr) return;
//         mp[col][row].insert(root->val);
//         vertGo(root->left, row + 1, col - 1, mp);
//         vertGo(root->right, row + 1, col + 1, mp);
//     }

// public:
//     vector<vector<int>> verticalTraversal(node* root) {
//         if(root == nullptr) return {};

//         map<int, map<int, multiset<int>>> mp; // col -> row -> values
//         vertGo(root, 0, 0, mp);

//         vector<vector<int>> res;
//         for(auto& [col, rowMap] : mp) {
//             vector<int> colResult;
//             for(auto& [row, values] : rowMap) {
//                 for(int val : values) {
//                     colResult.push_back(val);
//                 }
//             }
//             res.push_back(colResult);
//         }
//         return res;
//     }

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
        q->left->right = new node(6);
        q->right->left = new node(5);
        q->right->right = new node(7);

        Solution sol;
        vvi res = sol.verticalTraversal(p);

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

