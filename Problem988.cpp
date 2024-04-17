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
    string smallestFromLeaf(TreeNode* root) {
        string result = "";
        queue<pair<TreeNode*, string>> bfsQueue;
        bfsQueue.push({root, result + char('a' + root->val)});
        while (!bfsQueue.empty()) {
            for (int k = bfsQueue.size() - 1; k >= 0; --k) {
                auto[currNode, currString] = bfsQueue.front();
                bfsQueue.pop();
                if (currNode->left) {
                    bfsQueue.push({currNode->left, currString + char('a' + currNode->left->val)});
                }
                if (currNode->right) {
                    bfsQueue.push({currNode->right, currString + char('a' + currNode->right->val)});
                }
                if (!currNode->left && !currNode->right) {
                    reverse(currString.begin(), currString.end());
                    if (result == "" || currString < result) {
                        result = currString;
                    }
                }
            }
        }
        return result;
    }
};

// bfs
// time: O(n ^ 2)
// space: O(n ^ 2)

