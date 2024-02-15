class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        vector<vector<int>> newIntervals;
        for (int i = 0; i < intervals.size(); ++i) { 
            if (toBeRemoved[1] <= intervals[i][0] || toBeRemoved[0] >= intervals[i][1]) {
                newIntervals.push_back(intervals[i]);
            } else {
                if (toBeRemoved[0] > intervals[i][0]) {
                    newIntervals.push_back({intervals[i][0], toBeRemoved[0]});
                }
                if (toBeRemoved[1] < intervals[i][1]) {
                    newIntervals.push_back({toBeRemoved[1], intervals[i][1]});
                }
            }
        }
        return newIntervals;
    }
};

// one pass
// time: O(n)
// space: O(1)

