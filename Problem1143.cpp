// class Solution {
// public:
//     int longestCommonSubsequence(string text1, string text2) {
//         vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), 0));
//         for (int i = 0; i < text1.size(); ++i) {
//             for (int j = 0; j < text2.size(); ++j) {
//                 int dp1 = text1[i] != text2[j] ? 0 : i > 0 && j > 0 ? 
//                           1 + dp[i - 1][j - 1] : 1;
//                 int dp2 = j > 0 ? dp[i][j - 1] : 0;
//                 int dp3 = i > 0 ? dp[i - 1][j] : 0;
//                 dp[i][j] = max({dp1, dp2, dp3});
//             }
//         }
//         return dp.back().back();
//     }
// };

// dp
// time: O(m * n)
// space: O(m * n)

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if (text2.size() > text1.size()) {
            return longestCommonSubsequence(text2, text1);
        }
        vector<int> prevDP(text2.size(), 0);
        for (int i = 0; i < text1.size(); ++i) {
            vector<int> newDP(text2.size(), 0);
            for (int j = 0; j < text2.size(); ++j) {
                int dp1 = text1[i] != text2[j] ? 0 : j > 0 ? 
                          1 + prevDP[j - 1] : 1;
                int dp2 = j > 0 ? newDP[j - 1] : 0;
                int dp3 = prevDP[j];
                newDP[j] = max({dp1, dp2, dp3});
            }
            prevDP = newDP;
        }
        return prevDP.back();
    }
};

// dp with space optimization
// time: O(m * n)
// space: O(min(m, n))

