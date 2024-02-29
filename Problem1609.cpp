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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> bfsQueue;
        int currLevel = 0;
        bfsQueue.push(root);
        while (!bfsQueue.empty()) {
            int preVal = currLevel % 2 ? INT_MAX : 0;
            for (int k = bfsQueue.size(); k > 0; --k) {
                TreeNode *currNode = bfsQueue.front();
                bfsQueue.pop();
                if (currLevel % 2 == 0 && (currNode->val % 2 == 0 || currNode->val <= preVal)
                    || currLevel % 2 == 1 && (currNode->val % 2 == 1 || currNode->val >= preVal)) {
                    return false;
                }
                if (currNode->left) {
                    bfsQueue.push(currNode->left);
                }
                if (currNode->right) {
                    bfsQueue.push(currNode->right);
                }
                preVal = currNode->val;
            }
            ++currLevel;
        }
        return true;
    }
};

// BFS
// time: O(n)
// space: O(n)
