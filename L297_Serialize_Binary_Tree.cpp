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

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    
    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }  
};

class Codec {
    public:
    string serialize(TreeNode* root) {
        string ser = "";
        if(root == nullptr) {
            ser += "$";
            return ser;
        }

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* tem = q.front();
            q.pop();
            if(tem == nullptr) {
                ser += "$,";
            }
            else {
                ser += to_string(tem->val) + ',';
                q.push(tem->left);
                q.push(tem->right);
            }
        }
        return ser;
    }

    TreeNode* deserialize(string s) {
        if(s == "$" || s.empty()) {
            return nullptr;
        }

        int i = 0;
        string tem;
        vector<string> treeTreeNodes;
        while(i < s.length()) {
            if(s[i] == ',') {
                treeTreeNodes.push_back(tem);
                tem = "";
            }
            else {
                tem += s[i];
            }
            i++;
        }
        if(!tem.empty()) {
            treeTreeNodes.push_back(tem);
        }

        i = 0;
        queue<TreeNode*> q;
        TreeNode* root = new TreeNode(stoll(treeTreeNodes[i++]));
        q.push(root);
        while(!q.empty() && i < treeTreeNodes.size()) {
            TreeNode* it = q.front();
            q.pop();
            if(i < treeTreeNodes.size()) {
                if(treeTreeNodes[i] == "$") {
                    it->left = nullptr;
                }
                else {
                    it->left = new TreeNode(stoll(treeTreeNodes[i]));
                    q.push(it->left);
                }
                i++;
            }

            // Process right child with bounds checking
            if(i < treeTreeNodes.size()) {
                if(treeTreeNodes[i] == "$") {
                    it->right = nullptr;
                }
                else {
                    it->right = new TreeNode(stoll(treeTreeNodes[i]));
                    q.push(it->right);
                }
                i++;
            }
        }
        return root;
    }
};

void deleteTree(TreeNode* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

void printInorder(TreeNode* root) {
    if(!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

void printTree(TreeNode* root, int depth = 0) {
    if (!root) return;
    printTree(root->right, depth + 1);
    for (int i = 0; i < depth; i++) cout << "    ";
    cout << root->val << endl;
    printTree(root->left, depth + 1);
}

bool areTreesEqual(TreeNode* t1, TreeNode* t2) {
    if (!t1 && !t2) return true;
    if (!t1 || !t2) return false;
    return (t1->val == t2->val) && 
           areTreesEqual(t1->left, t2->left) && 
           areTreesEqual(t1->right, t2->right);
}

void testSerializeDeserialize(int testNum, TreeNode* original, const string& description) {
    cout << "\n=== Test Case " << testNum << ": " << description << " ===" << endl;
    
    Codec codec;
    
    // Serialize
    string serialized = codec.serialize(original);
    cout << "Serialized: " << serialized << endl;
    
    // Deserialize
    TreeNode* deserialized = codec.deserialize(serialized);
    
    // Compare trees
    bool isEqual = areTreesEqual(original, deserialized);
    cout << "Round-trip test: " << (isEqual ? "PASS" : "FAIL") << endl;
    
    if (original) {
        cout << "Original inorder: ";
        printInorder(original);
        cout << endl;
    } else {
        cout << "Original: null tree" << endl;
    }
    
    if (deserialized) {
        cout << "Deserialized inorder: ";
        printInorder(deserialized);
        cout << endl;
    } else {
        cout << "Deserialized: null tree" << endl;
    }
    
    // Clean up deserialized tree
    deleteTree(deserialized);
}

int32_t main() {
    cout << "Testing Serialize and Deserialize Functions" << endl;
    cout << "===========================================" << endl;
    
    // Test Case 1: Empty tree
    TreeNode* test1 = nullptr;
    testSerializeDeserialize(1, test1, "Empty tree");
    
    // Test Case 2: Single TreeNode
    TreeNode* test2 = new TreeNode(1);
    testSerializeDeserialize(2, test2, "Single TreeNode");
    
    // Test Case 3: Two TreeNodes - left child only
    TreeNode* test3 = new TreeNode(1);
    test3->left = new TreeNode(2);
    testSerializeDeserialize(3, test3, "Two TreeNodes - left child only");
    
    // Test Case 4: Two TreeNodes - right child only
    TreeNode* test4 = new TreeNode(1);
    test4->right = new TreeNode(3);
    testSerializeDeserialize(4, test4, "Two TreeNodes - right child only");
    
    // Test Case 5: LeetCode Example 1
    TreeNode* test5 = new TreeNode(1);
    test5->left = new TreeNode(2);
    test5->right = new TreeNode(3);
    test5->right->left = new TreeNode(4);
    test5->right->right = new TreeNode(5);
    testSerializeDeserialize(5, test5, "LeetCode Example 1");
    
    // Test Case 6: Complete binary tree
    TreeNode* test6 = new TreeNode(1);
    test6->left = new TreeNode(2);
    test6->right = new TreeNode(3);
    test6->left->left = new TreeNode(4);
    test6->left->right = new TreeNode(5);
    test6->right->left = new TreeNode(6);
    test6->right->right = new TreeNode(7);
    testSerializeDeserialize(6, test6, "Complete binary tree");
    
    // Test Case 7: Left-skewed tree
    TreeNode* test7 = new TreeNode(1);
    test7->left = new TreeNode(2);
    test7->left->left = new TreeNode(3);
    testSerializeDeserialize(7, test7, "Left-skewed tree");
    
    // Test Case 8: Right-skewed tree
    TreeNode* test8 = new TreeNode(1);
    test8->right = new TreeNode(2);
    test8->right->right = new TreeNode(3);
    testSerializeDeserialize(8, test8, "Right-skewed tree");
    
    // Test Case 9: Tree with negative numbers
    TreeNode* test9 = new TreeNode(-1);
    test9->left = new TreeNode(-2);
    test9->right = new TreeNode(3);
    test9->left->left = new TreeNode(-4);
    testSerializeDeserialize(9, test9, "Tree with negative numbers");
    
    // Test Case 10: Tree with zeros
    TreeNode* test10 = new TreeNode(0);
    test10->left = new TreeNode(0);
    test10->right = new TreeNode(0);
    testSerializeDeserialize(10, test10, "Tree with zeros");
    
    // Test Case 11: Large numbers
    TreeNode* test11 = new TreeNode(1000000);
    test11->left = new TreeNode(-999999);
    test11->right = new TreeNode(2000000);
    testSerializeDeserialize(11, test11, "Tree with large numbers");
    
    // Test Case 12: Deep tree
    TreeNode* test12 = new TreeNode(1);
    test12->left = new TreeNode(2);
    test12->left->left = new TreeNode(3);
    test12->left->left->left = new TreeNode(4);
    test12->left->left->left->left = new TreeNode(5);
    testSerializeDeserialize(12, test12, "Deep tree (5 levels)");
    
    // Test Case 13: Manual deserialization test
    cout << "\n=== Manual Deserialization Tests ===" << endl;
    
    Codec codec;
    
    // Test manual strings
    vector<string> testStrings = {
        "$",
        "1,$,$,",
        "1,2,$,$,$,",
        "1,$,3,$,$,",
        "1,2,$,$,3,4,$,$,5,$,$,",
        "0,0,$,$,0,$,$,"
    };
    
    vector<string> descriptions = {
        "Empty tree string",
        "Single TreeNode string",
        "Left child only string", 
        "Right child only string",
        "Complex tree string",
        "Zero values string"
    };
    
    for(int i = 0; i < testStrings.size(); i++) {
        cout << "\nManual Test " << (i+1) << ": " << descriptions[i] << endl;
        cout << "Input string: " << testStrings[i] << endl;
        
        TreeNode* result = codec.deserialize(testStrings[i]);
        if(result) {
            cout << "Deserialized inorder: ";
            printInorder(result);
            cout << endl;
            cout << "Re-serialized: " << codec.serialize(result) << endl;
        } else {
            cout << "Result: null tree" << endl;
        }
        deleteTree(result);
    }
    
    cout << "\n===========================================" << endl;
    cout << "All test cases completed!" << endl;
    
    // Clean up original trees
    deleteTree(test2);
    deleteTree(test3);
    deleteTree(test4);
    deleteTree(test5);
    deleteTree(test6);
    deleteTree(test7);
    deleteTree(test8);
    deleteTree(test9);
    deleteTree(test10);
    deleteTree(test11);
    deleteTree(test12);
    
    return 0;
}