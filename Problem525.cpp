class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int maxLen = 0;
        int curr = 0;
        unordered_map<int, int> sumPosMap = {{0, -1}};
        for (int i = 0; i < nums.size(); ++i) {
            curr += nums[i] ? 1 : -1;
            if (sumPosMap.count(curr)) {
                maxLen = max(maxLen, i - sumPosMap[curr]);
            } else {
                sumPosMap[curr] = i;
            }
        }
        return maxLen;
    }
};

// hash map
// time: O(n)
// space: O(n)

