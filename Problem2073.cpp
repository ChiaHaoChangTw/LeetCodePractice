class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time = 0;
        int target = tickets[k];
        for (int i = 0; i < k; ++i) {
            time += min(target, tickets[i]);
        }
        time += target;
        for (int i = k + 1; i < tickets.size(); ++i) {
            time += min(target - 1, tickets[i]);
        }
        return time;
    }
};

// one pass
// time: O(n)
// space: O(1)

