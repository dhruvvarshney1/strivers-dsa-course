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
    node* searchBST(node* root, int x) {
        if(root == nullptr || root->val == x) {
            return root;
        }

        if(root->val > x) {
            return searchBST(root->left, x);
        }
        
        return searchBST(root->right, x);
    }

    int minBST(node* root) {
        if(root == nullptr) {
            return INT_MAX;
        }

        while(root->left != nullptr) {
            root = root->left;
        }

        return root->val;
    }

    int maxBST(node* root) {
        if(root == nullptr) {
            return INT_MIN;
        }

        while(root->right != nullptr) {
            root = root->right;
        }

        return root->val;
    }

    int ceilBST(node* root, int x) {
        int ceil = -1;
        while(root != nullptr) {

            if(x > root->val) {
                root = root->right;
            }
            else {
                ceil = root->val;
                root = root->left;
            }
        }

        return ceil;
    }

    int floorBST(node* root, int x) {
        int flo = -1;
        while(root != nullptr) {

            if(x < root->val) {
                root = root->left;
            }
            else {
                flo = root->val;
                root = root->right;
            }
        }

        return flo;
    }

    node* insertIntoBST(node* root, int x) {
        if(root == nullptr) {
            return new node(x);
        }

        if(x > root->val) {
            root->right = insertIntoBST(root->right, x);
        }
        else {
            root->left = insertIntoBST(root->left, x);
        }
        return root;
    }

    node* deletenode(node* root, int x) {
        if(root == nullptr) {
            return nullptr;
        }

        if(x > root->val) {
            root->right = deletenode(root->right, x);
        }
        else if(x < root->val){
            root->left = deletenode(root->left, x);
        }
        else {
            if(root->left == nullptr && root->right == nullptr) {
                delete root;
                return nullptr;
            }
            else if(root->left == nullptr) {
                node* tem = root->right;
                delete root;
                return tem;
            }
            else if(root->right == nullptr) {
                node* tem = root->left;
                delete root;
                return tem;
            }
            else {
                node* tem = root->right;
                while(tem->left != nullptr) {
                    tem = tem->left;
                } 

                root->val = tem->val;
                root->right = deletenode(root->right, tem->val);
            }
        }
        return root;
    }
};

