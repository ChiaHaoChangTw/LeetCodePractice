class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> farms;
        for (int i = 0; i < land.size(); ++i) {
            for (int j = 0; j < land[0].size(); ++j) {
                if (land[i][j]) {
                    int ii = i;
                    int jj = j;
                    for (ii = i; ii < land.size() && land[ii][j]; ++ii) {
                        for (jj = j; jj < land[0].size() && land[ii][jj]; ++jj) {
                            land[ii][jj] = 0;
                        }
                    }
                    farms.push_back({i, j, ii - 1, jj - 1});
                    j = jj;
                }
            }
        }
        return farms;
    }
};

// greedy
// time: O(m * n)
// space: O(1)

