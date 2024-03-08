class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int maxProf = 0;
        int i = 0;
        int best = 0;
        vector<vector<int>> jobs;
        for (int j = 0; j < difficulty.size(); ++j) {
            jobs.push_back({difficulty[j], profit[j]});
        }
        sort(jobs.begin(), jobs.end());
        sort(worker.begin(), worker.end());
        for (const auto &w: worker) {
            while (i < jobs.size() && jobs[i][0] <= w) {
                best = max(best, jobs[i][1]);
                ++i;
            }
            maxProf += best;
        }
        return maxProf;
    }
};

// sorting
// time: O(n log n + m log m)
// space: O(n)

