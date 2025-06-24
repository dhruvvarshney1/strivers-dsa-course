/*
    Author: Dhruv Varshney
    curr->vale - 2025/05/18
    Time - 21:56:32
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
    void pre(node* root, vi &a) {
        if(root == nullptr) {
            return;
        }
        a.push_back(root->val);
        pre(root->left, a);
        pre(root->right, a);
    }
    void in(node* root, vi &a) {
        if(root == nullptr) {
            return;
        }
        in(root->left, a);
        a.push_back(root->val);
        in(root->right, a);
    }
    void post(node* root, vi &a) {
        if(root == nullptr) {
            return;
        }
        post(root->left, a);
        post(root->right, a);
        a.push_back(root->val);
    }
public:

    // DFS : Depth First Search - Recursive Approach
    vector<int> preorder(node* root) {
        vector<int> ans;
        pre(root, ans);
        return ans;
    }
    vector<int> inorder(node* root) {
        vector<int> ans;
        in(root, ans);
        return ans;
    }
    vector<int> postorder(node* root) {
        vector<int> ans;
        post(root, ans);
        return ans;
    }

    // Iterative Approach
    vi preorderIterative(node* root) {
        vi res;
        if(root == nullptr) return res;
        stack<node*> st;
        st.push(root);

        while(!st.empty()) {
            node* curr(st.top());
            st.pop();
            res.push_back(curr->val);

            if(curr->right) st.push(curr->right);
            if(curr->left) st.push(curr->left);
        }
        return res;
    }

    vi inorderIterative(node* root) {
        vi res;
        if(root == nullptr) return res;
        stack<node*> st;
        node* curr = root;
        while(curr != nullptr|| !st.empty()) {
            while(curr != nullptr) {
                st.push(curr);
                curr=curr->left;
            }
            curr = st.top();
            res.push_back(curr->val);
            st.pop();
            curr = curr->right;
        }
        return res;
    }

    vi postorderIterative_1(node* root) {
        vi res;
        if(root == nullptr) {
            return res;
        }
        stack<node*> st1, st2;
        st1.push(root);
        while(!st1.empty()) {
            node* tem = st1.top();
            st1.pop();
            st2.push(tem);
            if(tem->left  != nullptr) st1.push(tem->left);
            if(tem->right != nullptr) st1.push(tem->right);
        }
        while(!st2.empty()) {
            res.push_back(st2.top()->val);
            st2.pop();
        }
        return res;
    }

    vi postorderIterative(node* root) {
        vi res;
        if(root == nullptr) {
            return res;
        }
        stack<node*> st;
        node* curr = root;
        node* prev = nullptr;

        while(!st.empty() || curr != nullptr) {
            while(curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            }

            curr = st.top();
            if(curr->right && prev != curr->right) {
                // some code
                curr = curr->right;
            }
            else {
                res.push_back(st.top()->val);
                st.pop();
                prev = curr;
                curr = nullptr;
            }
        }
        return res;
    }

    vvi treeTraversal(node* root) {
        vvi res(3);
        if(root == nullptr) return res;

        stack<pair<node*, int>>st;
        st.push(make_pair(root, 0));

        while(!st.empty()) {

            auto [curr, idx] = st.top();
            st.pop();

            if(idx == 0) {
                res[idx].push_back(curr->val);
                st.push(make_pair(curr, 1));
                if(curr->left) {
                    curr = curr->left;
                    st.push(make_pair(curr, 0));
                }
            }
            else if(idx == 1) {
                res[idx].push_back(curr->val);
                st.push(make_pair(curr, 2));
                if(curr->right) {
                    curr = curr->right;
                    st.push(make_pair(curr, 0));
                }
            }
            else {
                res[idx].push_back(curr->val);
            }
        }
        return res;
    }

    // BFS: Breadth First Search
    vector<vector<int>> levelOrder(node* root) {
        vector<vector<int>> res;
        if (root == nullptr) return res;

        queue<node*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();
            vector<int> a;
            for (int i = 0; i < n; i++) {
                node* curr = q.front();
                q.pop();
                a.push_back(curr->val);
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            res.push_back(a);
        }
        return res;
    }
};

int32_t main() {
    /*
        Example Tree:
              1
             / \
            2   3
           / \
          4   5
    */

    // Creating nodes
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);

    Solution sol;
    vvi a = sol.treeTraversal(root);
    for(auto &x : a) {
        for(int y : x) {
            cout << y << ' ';
        }
        cout << endl;
    }

    // Clean up memory (not strictly necessary for small test, but good practice)
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
