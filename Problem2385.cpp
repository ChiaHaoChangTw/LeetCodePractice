class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        int level = -1;
        unordered_map<int, vector<int>> g;
        unordered_set<int> visited;
        queue<int> bfsQueue;
        makeGraph(root, g);
        bfsQueue.push(start);
        visited.insert(start);
        while (!bfsQueue.empty()) {
            for (int k = bfsQueue.size() - 1; k >= 0; --k) {
                int curr = bfsQueue.front();
                bfsQueue.pop();
                for (const auto &next: g[curr]) {
                    if (!visited.count(next)) {
                        bfsQueue.push(next);
                        visited.insert(next);
                    }
                }
            }
            ++level;
        }
        return level;
    }

private:
    void makeGraph(TreeNode *node, unordered_map<int, vector<int>> &g) {
        if (node->left) {
            g[node->val].push_back(node->left->val);
            g[node->left->val].push_back(node->val);
            makeGraph(node->left, g);
        }
        if (node->right) {
            g[node->val].push_back(node->right->val);
            g[node->right->val].push_back(node->val);
            makeGraph(node->right, g);
        }
    }
};

// convert to graph
// bfs
// time: O(n)
// space: O(n)
