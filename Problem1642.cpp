class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> bs;
        for (int i = 0; i < heights.size() - 1; ++i) {
            int diff = heights[i + 1] - heights[i];
            if (diff <= 0) {
                continue;
            } else if (diff <= bricks) {
                bricks -= diff;
                bs.push(diff);
            } else if (ladders > 0) {
                --ladders;
                if (!bs.empty() && bs.top() > diff) {
                    bricks += bs.top() - diff;
                    bs.pop();
                    bs.push(diff);
                }
            } else {
                return i;
            }
        }
        return heights.size() - 1;
    }
};

// greedy
// priority queue
// time: O(n log n)
// space: O(n)

