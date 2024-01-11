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
    int maxAncestorDiff(TreeNode* root) {
        int maxDiff = 0;
        dfs(root, maxDiff, root->val, root->val);
        return maxDiff;
    }

private:
    void dfs(TreeNode *root, int &maxDiff, int minVal, int maxVal) {
        minVal = min(minVal, root->val);
        maxVal = max(maxVal, root->val);
        maxDiff = max({maxDiff, abs(root->val - minVal), 
                       abs(root->val - maxVal)});
        if (root->left) {
            dfs(root->left, maxDiff, minVal, maxVal);
        }
        if (root->right) {
            dfs(root->right, maxDiff, minVal, maxVal);
        }
    }
};

// dfs
// time: O(n)
// space: O(n)

