class Solution {
public:
    int goodNodes(TreeNode* root) {
        return goodNodes(root, INT_MIN);
    }
    
private:
    int goodNodes(TreeNode* root, int currMax) {
        if(!root) {
            return 0;
        }
        if(root->val >= currMax) {
            return 1 + goodNodes(root->left, root->val) + goodNodes(root->right, root->val);
        }
        return goodNodes(root->left, currMax) + goodNodes(root->right, currMax);
    }
};
