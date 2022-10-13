class Solution {
public:
    int maxPathSum(TreeNode* root) {
        localMaxPathSum(root);
        return maxSum;
    }

private:
    int maxSum = INT_MIN;
    
    int localMaxPathSum(TreeNode* root) {
        if(!root) {
            return 0;
        }
        
        int leftMaxSum = localMaxPathSum(root->left);
        int rightMaxSum = localMaxPathSum(root->right);
        int currNodeVal = root->val;
        
        int result = max({leftMaxSum + currNodeVal, rightMaxSum + currNodeVal, currNodeVal});
        maxSum = max({maxSum, result, leftMaxSum + currNodeVal + rightMaxSum});
        
        return result;
    }
};

