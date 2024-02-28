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
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        int bl = root->val;
        queue<TreeNode*> bfsQueue;
        bfsQueue.push(root);
        while (!bfsQueue.empty()) {
            bl = bfsQueue.front()->val;
            for (int k = bfsQueue.size() - 1; k >= 0; --k) {
                TreeNode *curr = bfsQueue.front();
                bfsQueue.pop();
                if (curr->left) {
                    bfsQueue.push(curr->left);
                }
                if (curr->right) {
                    bfsQueue.push(curr->right);
                }
            }
        }
        return bl;
    }
};

// bfs
// time: O(n)
// space: O(n)

