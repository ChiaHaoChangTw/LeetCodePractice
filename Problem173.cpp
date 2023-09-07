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

 /*
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        traverseBST(root);
        currPos = -1;
    }
    
    int next() {
        ++currPos;
        return sortedVec[currPos];
    }
    
    bool hasNext() {
        return currPos + 1 < sortedVec.size();
    }

private:
    vector<int> sortedVec; 
    int currPos;

    void traverseBST(TreeNode* root) {
        if (!root) {
            return;
        }
        traverseBST(root->left);
        sortedVec.push_back(root->val);
        traverseBST(root->right);
    }
};
*/

class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        pushLeftNodes(root);
    }
    
    int next() {
        TreeNode* curr = nodeStack.top();
        nodeStack.pop();
        if (curr->right) {
            pushLeftNodes(curr->right);
        }
        return curr->val;
    }
    
    bool hasNext() {
        return !nodeStack.empty();
    }

private:
    stack<TreeNode*> nodeStack; 

    void pushLeftNodes(TreeNode* curr) {
        while (curr) {
            nodeStack.push(curr);
            curr = curr->left;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

// recursion
// time O(1)
// space O(n)

// iteration
// time O(1)
// space O(h)

