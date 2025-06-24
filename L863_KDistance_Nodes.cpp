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
    void dfs(node* root, node* prev, map<node*, node*> &nodeMap, vector<int> &res, int k) {
        if(!root) return;

        if(k == 0) {
            res.push_back(root->val);
            return;
        }
        if(root->left != prev) {
            dfs(root->left, root, nodeMap, res, k - 1);
        }
        if(root->right != prev) {
            dfs(root->right, root, nodeMap, res, k - 1);
        }
        if(nodeMap[root] != prev) {
            dfs(nodeMap[root], root, nodeMap, res, k - 1);
        }
    }
    public:
    vector<int> distanceK(node* root, node* tgt, int k) {
        vector<int> res;
        if(root == nullptr) {
            return res;
        }

        map<node*, node*> nodeMap;
        queue<node*> q;
        q.push(root);
        while(!q.empty()) {
            node* it = q.front();
            if(it->left) {
                nodeMap[it->left] = it;
                q.push(it->left);
            }
            if(it->right) {
                nodeMap[it->right] = it;
                q.push(it->right);
            }
            q.pop();
        }
        dfs(tgt, nullptr, nodeMap, res, k);
        return res;
    }

    void deleteTree(node* root) {
        if(root == nullptr) {
            return;
        }
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
};


// Helper function to find a node with given value
node* findNode(node* root, int val) {
    if(!root) return nullptr;
    if(root->val == val) return root;
    
    node* left = findNode(root->left, val);
    if(left) return left;
    
    return findNode(root->right, val);
}

signed main() {
    Solution sol;
    
    // Test Case 1: Tree [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
    node* root1 = new node(3);
    root1->left = new node(5);
    root1->right = new node(1);
    root1->left->left = new node(6);
    root1->left->right = new node(2);
    root1->right->left = new node(0);
    root1->right->right = new node(8);
    root1->left->right->left = new node(7);
    root1->left->right->right = new node(4);
    
    node* target1 = findNode(root1, 5);
    vector<int> result1 = sol.distanceK(root1, target1, 2);
    
    for(int val : result1) {
        cout << val << " ";
    }
    cout << endl;
    
    // Test Case 2: Tree [1], target = 1, k = 3
    node* root2 = new node(1);
    node* target2 = findNode(root2, 1);
    vector<int> result2 = sol.distanceK(root2, target2, 3);
    
    for(int val : result2) {
        cout << val << " ";
    }
    cout << endl;
    
    // Test Case 3: Tree [0,1,null,3,2], target = 2, k = 1
    node* root3 = new node(0);
    root3->left = new node(1);
    root3->left->left = new node(3);
    root3->left->right = new node(2);
    
    node* target3 = findNode(root3, 2);
    vector<int> result3 = sol.distanceK(root3, target3, 1);
    
    for(int val : result3) {
        cout << val << " ";
    }
    cout << endl;
    
    // Test Case 4: Tree [0,2,1,null,null,3], target = 3, k = 3
    node* root4 = new node(0);
    root4->left = new node(2);
    root4->right = new node(1);
    root4->right->left = new node(3);
    
    node* target4 = findNode(root4, 3);
    vector<int> result4 = sol.distanceK(root4, target4, 3);
    
    for(int val : result4) {
        cout << val << " ";
    }
    cout << endl;
    
    // Clean up memory
    sol.deleteTree(root1);
    sol.deleteTree(root2);
    sol.deleteTree(root3);
    sol.deleteTree(root4);
    
    return 0;
}