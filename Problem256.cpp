class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int prevR = 0;
        int prevB = 0;
        int prevG = 0;
        for (const auto &cost: costs) {
            int currR = min(prevB, prevG) + cost[0];
            int currB = min(prevR, prevG) + cost[1];
            int currG = min(prevR, prevB) + cost[2];
            prevR = currR;
            prevB = currB;
            prevG = currG;
        }
        return min({prevR, prevB, prevG});
    }
};

// dp with space optimized
// time: O(n)
// space: O(1)

