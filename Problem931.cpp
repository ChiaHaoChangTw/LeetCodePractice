class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<int> dp = matrix[0];
        for (int i = 1; i < matrix.size(); ++i) {
            vector<int> newDP(matrix.size(), 0);
            for (int j = 0; j < matrix[0].size(); ++j) {
                int l = j - 1 >= 0 ? dp[j - 1] : INT_MAX;
                int m = dp[j];
                int r = j + 1 < matrix[0].size() ? dp[j + 1] : INT_MAX;
                newDP[j] = min({l, m, r}) + matrix[i][j];
            }
            dp = newDP;
        }
        return *min_element(dp.begin(), dp.end());
    }
};

// dp space optimized
// time: O(n ^ 2)
// space: O(1)

