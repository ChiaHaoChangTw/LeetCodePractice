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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<pair<TreeNode*, TreeNode*>> bfsQueue;
        bfsQueue.push({p, q});
        while (!bfsQueue.empty()) {
            TreeNode* currp = bfsQueue.front().first;
            TreeNode* currq = bfsQueue.front().second;
            bfsQueue.pop();
            if (!currp && !currq) {
                continue;
            } 
            if ((!currp || !currq) || currp->val != currq->val) {
                return false;
            }
            bfsQueue.push({currp->left, currq->left});
            bfsQueue.push({currp->right, currq->right});
        }
        return true;
    }
};

// queue
// time: O(n)
// space: O(n)

