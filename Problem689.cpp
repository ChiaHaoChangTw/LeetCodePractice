class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<vector<int>> dp(nums.size() - k + 1, vector<int>(3, 0));
        vector<vector<vector<int>>> trace(nums.size() - k + 1, vector<vector<int>>(3));
        vector<int> subSum(nums.size() - k + 1, 0);
        int currSum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            currSum += nums[i];
            if (i - k >= 0) {
                currSum -= nums[i - k];
            }
            if (i - k + 1 >= 0) {
                subSum[i - k + 1] = currSum;
            }
        }
        for (int i = dp.size() - 1; i >= 0; --i) {
            for (int j = 0; j < dp[0].size(); ++j) {
                int next = i + 1 < dp.size() ? dp[i + 1][j] : 0;
                int curr = i + k < dp.size() && j - 1 >= 0 ? dp[i + k][j - 1] : 0;
                curr += subSum[i];
                if (next > curr) {
                    trace[i][j] = trace[i + 1][j];
                    dp[i][j] = next;
                } else if (next <= curr && i + k < dp.size() && j - 1 >= 0) {   
                    trace[i][j] = trace[i + k][j - 1];
                    trace[i][j].push_back(i);
                    dp[i][j] = curr;
                } else {
                    trace[i][j] = {i};
                    dp[i][j] = curr;
                }
            }
        }
        reverse(trace.front().back().begin(), trace.front().back().end());
        return trace.front().back();
    }
};

// dp
// time: O(n)
// space: O(n)

