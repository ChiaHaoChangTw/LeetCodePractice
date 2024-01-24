/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// class Solution {
// public:
//     int pseudoPalindromicPaths (TreeNode* root) {
//         int count = 0;
//         unordered_set<int> odds;
//         dfs(root, odds, count);
//         return count;
//     }

// private:
//     void dfs(TreeNode *node, unordered_set<int> &odds, int &count) {
//         if (!node) {
//             return;
//         }
//         if (odds.count(node->val)) {
//             odds.erase(node->val);
//         } else {
//             odds.insert(node->val);
//         }
//         dfs(node->left, odds, count);
//         dfs(node->right, odds, count);
//         if (!node->left && !node->right) {
//             count += odds.size() <= 1;
//         }
//         if (odds.count(node->val)) {
//             odds.erase(node->val);
//         } else {
//             odds.insert(node->val);
//         }
//     }
// };

// hash set
// time: O(n)
// space: O(n)

// class Solution {
// public:
//     int pseudoPalindromicPaths (TreeNode* root) {
//         int count = 0;
//         dfs(root, 0, count);
//         return count;
//     }

// private:
//     void dfs(TreeNode *node, int path, int &count) {
//         path ^= (1 << node->val);
//         if (!node->left && !node->right) {
//             count += (path & (path - 1)) == 0;
//         }
//         if (node->left) {
//             dfs(node->left, path, count);
//         }
//         if (node->right) {
//             dfs(node->right, path, count);
//         }
//     }
// };

// recursive
// XOR
// time: O(n)
// space: O(n)

class Solution {
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        int count = 0;
        stack<pair<TreeNode*, int>> nodePathStk;
        nodePathStk.push(make_pair(root, 0));
        while (!nodePathStk.empty()) {
            TreeNode *node = nodePathStk.top().first;
            int path = nodePathStk.top().second;
            nodePathStk.pop();
            path ^= (1 << node->val);
            if (!node->left && !node->right) {
                count += (path & (path - 1)) == 0;
            }
            if (node->left) {
                nodePathStk.push(make_pair(node->left, path));
            }
            if (node->right) {
                nodePathStk.push(make_pair(node->right, path));
            }
        } 
        return count;
    }
};

// iterative
// XOR
// time: O(n)
// space: O(n)

