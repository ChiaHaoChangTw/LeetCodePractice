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
//     bool isSymmetric(TreeNode* root) {
//         return check(root->left, root->right);
//     }

// private:
//     bool check(TreeNode *node1, TreeNode *node2) {
//         if (!node1 && !node2) {
//             return true;
//         } else if (node1 && node2) {
//             return node1->val == node2->val && 
//                    check(node1->right, node2->left) &&
//                    check(node1->left, node2->right);
//         }
//         return false;
//     }
// };

// recursive
// time: O(n)
// space: O(n)

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        nodeQueue.push(root);
        while (!nodeQueue.empty()) {
            TreeNode *node1 = nodeQueue.front();
            nodeQueue.pop();
            TreeNode *node2 = nodeQueue.front();
            nodeQueue.pop();
            if (!node1 && !node2) {
                continue;
            } else if (!node1 || !node2) {
                return false;
            } else if (node1->val != node2->val) {
                return false;
            }
            nodeQueue.push(node1->left);
            nodeQueue.push(node2->right);
            nodeQueue.push(node1->right);
            nodeQueue.push(node2->left);
        }
        return true;
    }
};

// iterative
// time: O(n)
// space: O(n)

