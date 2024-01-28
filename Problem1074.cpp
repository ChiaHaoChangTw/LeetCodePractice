class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int count = 0;
        vector<vector<int>> prefixSum(matrix.size(), 
                                      vector<int>(matrix[0].size(), 0));
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                int u = i - 1 >= 0 ? prefixSum[i - 1][j] : 0;
                int l = j - 1 >= 0 ? prefixSum[i][j - 1] : 0;
                int ul = i - 1 >= 0 && j - 1 >= 0 ? prefixSum[i - 1][j - 1] : 0;
                prefixSum[i][j] = u + l - ul + matrix[i][j];
            }
        }
        for (int r1 = 0; r1 < matrix.size(); ++r1) {
            for (int r2 = r1; r2 < matrix.size(); ++r2) {
                unordered_map<int, int> sumCountMap = {{0, 1}};
                for (int c = 0; c < matrix[0].size(); ++c) {
                    int currSum = prefixSum[r2][c] - 
                                    (r1 - 1 >= 0 ? prefixSum[r1 - 1][c] : 0);
                    count += sumCountMap[currSum - target];
                    ++sumCountMap[currSum];
                }
            }
        }
        return count;
    }
};

// prefix sum
// hash map (2 sum idea)
// time: O(m ^ 2 * n)
// space: O(m * n)

