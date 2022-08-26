class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<int> dp(text2.size(), 0);
        dp[0] = (text1[0] == text2[0]) ? 1 : 0;
        for(int j = 1; j < text2.size(); ++j) {
            dp[j] = (text1[0] == text2[j] || dp[j - 1]) ? 1 : 0;
        }
        for(int i = 1; i < text1.size(); ++i) {
            int preColRow = dp[0];
            dp[0] = (text1[i] == text2[0] || dp[0]) ? 1 : 0;
            int preCol = dp[0];
            for(int j = 1; j < text2.size(); ++j) {
                int temp = dp[j];
                if(text1[i] == text2[j]) {
                    dp[j] = max(dp[j], preColRow + 1);
                }
                dp[j] = max({dp[j], preCol, temp});
                preCol = dp[j];
                preColRow = temp;
            }
        }
        return dp.back();
    }
};
