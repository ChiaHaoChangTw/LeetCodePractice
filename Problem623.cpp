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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode *newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        dfs(root, val, depth, 1);
        return root;
    }

private:
    void dfs(TreeNode *currNode, const int &val, const int &depth, int currDepth) {
        if (!currNode) {
            return;
        }
        if (currDepth + 1 == depth) {
            TreeNode *newLeft = new TreeNode(val);
            TreeNode *newRight = new TreeNode(val);
            newLeft->left = currNode->left;
            newRight->right = currNode->right;
            currNode->left = newLeft;
            currNode->right = newRight;
            return;
        }
        dfs(currNode->left, val, depth, currDepth + 1);
        dfs(currNode->right, val, depth, currDepth + 1);
    }
};

// dfs
// time: O(N)
// space: O(N)

