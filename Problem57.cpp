class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        bool inserted = false;
        int i = 0;
        while (i < intervals.size() || !inserted) {
            vector<int> curr;
            if (!inserted && (i >= intervals.size() || newInterval[0] <= intervals[i][0])) {
                curr = newInterval;
                inserted = true;
            } else {
                curr = intervals[i];
                ++i;
            }
            if (result.empty() || curr[0] > result.back()[1]) {
                result.push_back(curr);
            } else {
                result.back()[1] = max(result.back()[1], curr[1]);
            }
        }
        return result;
    }
};

// vector
// time: O(n)
// space: O(1)

