class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int free = 0;
        int hold = -prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            free = max(free, hold + prices[i] - fee);
            hold = max(hold, free - prices[i]);
        }        
        return free;
    }
};

// dp
// time: O(n)
// space: O(1)

