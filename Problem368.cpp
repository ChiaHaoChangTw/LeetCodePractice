class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> lds;
        vector<pair<int, int>> dp(nums.size());
        int maxLen = -1;
        int maxPos = -1;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            dp[i] = {1, i};
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0 && dp[j].first + 1 > dp[i].first) {
                    dp[i] = {dp[j].first + 1, j};
                }
            }
            if (dp[i].first > maxLen) {
                maxLen = dp[i].first;
                maxPos = i;
            }
        }
        lds.push_back(nums[maxPos]);
        while (maxPos != dp[maxPos].second) {
            maxPos = dp[maxPos].second;
            lds.push_back(nums[maxPos]);
        }
        reverse(lds.begin(), lds.end());
        return lds;
    }
};

// dp
// time: O(n ^ 2)
// space: O(n)

