class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<vector<int>> result = {{lower, upper}};
        for (auto num: nums) {
            if (num == result.back()[0] && num == result.back()[1]) {
                result.pop_back();
            } else if (num == result.back()[0]) {
                result.back()[0] = num + 1;
            } else if (num == result.back()[1]) {
                result.back()[1] = num - 1;
            } else {
                result.back()[1] = num - 1;
                result.push_back({num + 1, upper});
            }
        }
        return result;
    }
};

// split
// time O(n)
// space O(1)

