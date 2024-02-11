class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<vector<int>>> memo(m, vector<vector<int>>(n, 
                                            vector<int>(n, -1)));
        return pick(grid, 0, 0, 0, n - 1, memo);
    }

private:
    int m = 0;
    int n = 0;

    int pick(const vector<vector<int>> &grid, int i1, int j1,
             int i2, int j2, vector<vector<vector<int>>> &memo) {
        if (memo[i1][j1][j2] != -1) {
            return memo[i1][j1][j2];
        }
        int maxSum = 0;
        int ii1 = i1 + 1;
        int ii2 = i2 + 1;
        memo[i1][j1][j2] = j1 == j2 ? grid[i1][j1] : grid[i1][j1] + grid[i2][j2];
        for (int jj1 = j1 - 1; jj1 <= j1 + 1; ++jj1) {
            for (int jj2 = j2 - 1; jj2 <= j2 + 1; ++jj2) {
                if (ii1 < m && ii2 < m && jj1 >= 0 && jj1 < n &&
                        jj2 >= 0 && jj2 < n) {
                    maxSum = max(maxSum, pick(grid, ii1, jj1, ii2, jj2, memo));
                }
            }
        }
        memo[i1][j1][j2] += maxSum;
        return memo[i1][j1][j2];
    }
};

// dp with memo
// time: O(m * n ^ 2)
// space: O(m * n ^ 2)

