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
    public:
    int widthOfBinaryTree(node* root) {
        if(!root) return 0;

        queue<tuple<node*, int, int>> q;
        q.push({root, 0, 0});
        map<int, pair<int, int>> xtr; // Use map instead of vector

        while(!q.empty()) {
            auto[tem, ro, col] = q.front();
            q.pop();
            
            // Initialize if not exists
            if(xtr.find(ro) == xtr.end()) {
                xtr[ro] = {col, col};
            } else {
                xtr[ro].first = min(xtr[ro].first, col);
                xtr[ro].second = max(xtr[ro].second, col);
            }
            
            if(tem->left) {
                q.push({tem->left, ro + 1, col - 1});
            }
            if(tem->right) {
                q.push({tem->right, ro + 1, col + 1});
            }
        }

        int width = 0;
        for(auto [level, bounds] : xtr) {
            width = max(width, abs(bounds.second - bounds.first)); // Fixed: added +1
        }

        return width;
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
    
    // Test Case 1: Complete binary tree
    cout << "Test Case 1 (Complete binary tree): ";
    node* root1 = new node(1);
    root1->left = new node(2);
    root1->right = new node(3);
    root1->left->left = new node(4);
    root1->left->right = new node(5);
    root1->right->left = new node(6);
    root1->right->right = new node(7);
    cout << sol.widthOfBinaryTree(root1) << '\n'; // Expected: 4
    sol.deleteTree(root1);
    
    // Test Case 2: Single node
    cout << "Test Case 2 (Single node): ";
    node* root2 = new node(1);
    cout << sol.widthOfBinaryTree(root2) << '\n'; // Expected: 1
    sol.deleteTree(root2);
    
    // Test Case 3: Empty tree
    cout << "Test Case 3 (Empty tree): ";
    cout << sol.widthOfBinaryTree(nullptr) << '\n'; // Expected: 0
    
    // Test Case 4: Left skewed tree
    cout << "Test Case 4 (Left skewed): ";
    node* root4 = new node(1);
    root4->left = new node(2);
    root4->left->left = new node(3);
    root4->left->left->left = new node(4);
    cout << sol.widthOfBinaryTree(root4) << '\n'; // Expected: 1
    sol.deleteTree(root4);
    
    // Test Case 5: Right skewed tree
    cout << "Test Case 5 (Right skewed): ";
    node* root5 = new node(1);
    root5->right = new node(2);
    root5->right->right = new node(3);
    root5->right->right->right = new node(4);
    cout << sol.widthOfBinaryTree(root5) << '\n'; // Expected: 1
    sol.deleteTree(root5);
    
    // Test Case 6: LeetCode Example 1
    /*
        1
       / \
      3   2
     / \   \
    5   3   9
    Expected: 4 (at level 3: positions would be 0,1,null,3 -> width = 4)
    */
    cout << "Test Case 6 (LeetCode Example 1): ";
    node* root6 = new node(1);
    root6->left = new node(3);
    root6->right = new node(2);
    root6->left->left = new node(5);
    root6->left->right = new node(3);
    root6->right->right = new node(9);
    cout << sol.widthOfBinaryTree(root6) << '\n'; // Expected: 4
    sol.deleteTree(root6);
    
    // Test Case 7: LeetCode Example 2
    /*
        1
       /
      3
     / \
    5   3
    Expected: 2
    */
    cout << "Test Case 7 (LeetCode Example 2): ";
    node* root7 = new node(1);
    root7->left = new node(3);
    root7->left->left = new node(5);
    root7->left->right = new node(3);
    cout << sol.widthOfBinaryTree(root7) << '\n'; // Expected: 2
    sol.deleteTree(root7);
    
    // Test Case 8: Wide at bottom
    cout << "Test Case 8 (Wide bottom): ";
    node* root8 = new node(1);
    root8->left = new node(2);
    root8->right = new node(3);
    root8->left->left = new node(4);
    root8->right->right = new node(7);
    cout << sol.widthOfBinaryTree(root8) << '\n'; // Expected: 4
    sol.deleteTree(root8);
    
    return 0;
}


