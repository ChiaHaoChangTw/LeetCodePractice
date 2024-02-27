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
    int diameterOfBinaryTree(TreeNode* root) {
        int dia = 0;
        dfs(root, dia);
        return dia;
    }

private:
    int dfs(TreeNode *curr, int &dia) {
        int l = curr->left ? dfs(curr->left, dia) + 1 : 0;
        int r = curr->right ? dfs(curr->right, dia) + 1 : 0;
        dia = max(dia, l + r);
        return max(l, r);
    }
};

// dfs
// time: O(n)
// space: O(n)

