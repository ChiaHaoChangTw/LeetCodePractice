class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> newNums(nums.size(), 0);
        int i = 0;
        int j = 1;
        for (const auto &num: nums) {
            if (num > 0) {
                newNums[i] = num;
                i += 2;
            } else if (num < 0) {
                newNums[j] = num;
                j += 2;
            }
        }
        return newNums;
    }
};

// 2 pointers
// time: O(n)
// space: O(n)

