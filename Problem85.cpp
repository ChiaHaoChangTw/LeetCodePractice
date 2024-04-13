class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxArea = 0;
        vector<int> dp(matrix[0].size(), 0);
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                dp[j] = matrix[i][j] == '1' ? dp[j] + 1 : 0;
            }
            maxArea = max(maxArea, findMax(dp));
        }
        return maxArea;
    }

private:
    int findMax(const vector<int> &heights) {
        int maxArea = 0;
        stack<int> indexStack;
        indexStack.push(-1);
        for (int i = 0; i < heights.size(); ++i) {
            while (indexStack.top() != -1 && heights[indexStack.top()] >= heights[i]) {
                int h = heights[indexStack.top()];
                indexStack.pop();
                maxArea = max(maxArea, h * (i - indexStack.top() - 1));
            }
            indexStack.push(i);
        }
        while (indexStack.top() != -1) {
            int h = heights[indexStack.top()];
            indexStack.pop();
            maxArea = max(maxArea, h * (int(heights.size()) - indexStack.top() - 1));
        }
        return maxArea;
    }
};

// monotonic increasing stack
// time: O(m * n)
// space: O(n)

