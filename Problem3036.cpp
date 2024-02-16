class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int count = 0;
        vector<int> kmp = pattern;
        vector<int> ps;
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] > nums[i + 1]) {
                ps.push_back(-1);
            } else if (nums[i] == nums[i + 1]) {
                ps.push_back(0);
            } else if (nums[i] < nums[i + 1]) {
                ps.push_back(1);
            }
        }
        kmp.push_back(INT_MAX);
        kmp.insert(kmp.end(), ps.begin(), ps.end());
        vector<int> dp(kmp.size(), 0);
        for (int i = 1; i < dp.size(); ++i) {
            int v = dp[i - 1];
            while (v && kmp[i] != kmp[v]) {
                v = dp[v - 1];
            }
            dp[i] = v + (kmp[i] == kmp[v]);
        }
        for (const auto &v: dp) {
            if (v == pattern.size()) {
                ++count;
            }
        }
        return count;
    }
};

// kmp

