class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total = 0;
        int maxLen = -1;
        int currSum = 0;
        int l = 0;
        for (const auto &num: nums) {
            total += num;
        }
        for (int r = 0; r < nums.size(); ++r) {
            currSum += nums[r];
            while (currSum > total - x && l <= r) {
                currSum -= nums[l];
                ++l;
            }
            if (currSum == total - x) {
                maxLen = max(maxLen, r - l + 1);
            }
        }
        return maxLen == -1 ? -1 : nums.size() - maxLen;
    }
};

// sliding window
// time: O(n)
// space: O(1)

