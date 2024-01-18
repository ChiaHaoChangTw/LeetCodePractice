// class Solution {
// public:
//     int maximumSum(vector<int>& arr) {
//         vector<int> dp(arr.size(), 0);
//         vector<int> skip(arr.size(), 0);
//         dp[0] = arr[0];
//         skip[0] = arr[0];
//         int maxSum = max(dp[0], skip[0]);
//         for (int i = 1; i < arr.size(); ++i) {
//             dp[i] = max(arr[i], arr[i] + dp[i - 1]);
//             skip[i] = max(arr[i] + skip[i - 1], dp[i - 1]);
//             maxSum = max({dp[i], skip[i], maxSum});
//         }
//         return maxSum;
//     }
// };

// dp
// OPT(i) = max(arr(i), arr(i) + OPT(i - 1)) -> max with no skip
// SKIP(i) = max(arr(i) + SKIP(i - 1), OPT(i - 1)) -> max with one skip
// time: O(n)
// space: O(n)

class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int dp = arr[0];
        int skip = arr[0];
        int maxSum = max(dp, skip);
        for (int i = 1; i < arr.size(); ++i) {
            skip = max(arr[i] + skip, dp);
            dp = max(arr[i], arr[i] + dp);
            maxSum = max({dp, skip, maxSum});
        }
        return maxSum;
    }
};

// dp space optimized
// time: O(n)
// space: O(1)

