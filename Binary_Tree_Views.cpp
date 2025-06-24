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
    int maxDepth(node* root) {
        if(root == nullptr) {
            return 0;
        }
        int ld = maxDepth(root->left);
        int rd = maxDepth(root->right);
        
        return 1 + max(ld, rd);
    }
    vi SimpletopView(node* root) {
        vi res;
        if(root == nullptr) {
            return res;
        }

        deque<int> st;
        node*tem = root;
        while(tem != nullptr) {
            st.push_back(tem->val);
            tem = tem->right;
        }
        tem = root;
        while(tem != nullptr) {
            tem = tem->left;
            if(tem != nullptr) st.push_front(tem->val);
        }
        return vector(st.begin(), st.end());
    }
    void bfs(node* root, int curr) {
        
    }
    public:
    vi topView(node* root) {
        vi res;
        if(root == nullptr) {
            return res;
        }
        map<int, int>mp;
        queue<pair<node*, int>> q;
        q.push(make_pair(root, 0));
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            node* tem = it.first;
            int col = it.second;

            if(mp.find(col) == mp.end()) {
                mp[col] = tem->val;
            }
            if(tem->left != nullptr) {
                q.push(make_pair(tem->left, col-1));
            }
            if(tem->right != nullptr) {
                q.push(make_pair(tem->right, col+1));
            }   
        }

        for(auto const&[k, v] : mp) {
            res.push_back(v);
        }
        return res;
    }
    vi bottomView(node* root) {
        vi res;
        if(root == nullptr) {
            return res;
        }

        map<int, int> mp;

        queue<pair<node*, int>> q;
        q.push({root, 0});
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            node* tem = it.first;
            int col = it.second;

            mp[col] = tem->val;
            
            if(tem->left != nullptr) {
                q.push(make_pair(tem->left, col-1));
            }
            if(tem->right != nullptr) {
                q.push(make_pair(tem->right, col+1));
            }
        }

        for(auto&it : mp) {
            res.push_back(it.second);
        }

        return res;
    }
    vi rightView(node* root) {
        vi res;
        if(root == nullptr) {
            return res; 
        }

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
    */
    
    node* root1 = new node(1);
    root1->left = new node(2);
    root1->right = new node(3);
    root1->left->left = new node(4);
    root1->left->right = new node(5);
    root1->right->left = new node(6);
    root1->right->right = new node(7);
    
    vi a1 = sol.bottomView(root1);
    for(int x : a1) {
        cout << x << ' ';
    }
    cout << '\n';
    sol.deleteTree(root1);
    
    /* Test Case 2: Single node
       10
    */
    
    node* root2 = new node(10);
    
    vi a2 = sol.bottomView(root2);
    for(int x : a2) {
        cout << x << ' ';
    }
    cout << '\n';
    sol.deleteTree(root2);
    
    /* Test Case 3: Left skewed tree
       1
      /
     2
    /
   3
  /
 4
    */
    
    node* root3 = new node(1);
    root3->left = new node(2);
    root3->left->left = new node(3);
    root3->left->left->left = new node(4);
    
    vi a3 = sol.bottomView(root3);
    for(int x : a3) {
        cout << x << ' ';
    }
    cout << '\n';
    sol.deleteTree(root3);
    
    /* Test Case 4: Right skewed tree
       1
        \
         2
          \
           3
            \
             4
    */
    
    node* root4 = new node(1);
    root4->right = new node(2);
    root4->right->right = new node(3);
    root4->right->right->right = new node(4);
    
    vi a4 = sol.bottomView(root4);
    for(int x : a4) {
        cout << x << ' ';
    }
    cout << '\n';
    sol.deleteTree(root4);
    
    /* Test Case 5: Complex tree with overlapping nodes
            20
           /  \
          8    22
         / \   / \
        5   3 4   25
           / \
          10  14
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
    
    vi a5 = sol.bottomView(root5);
    for(int x : a5) {
        cout << x << ' ';
    }
    cout << '\n';
    sol.deleteTree(root5);
    
    return 0;
}

