class Solution {
public:
    int rob(vector<int>& nums) {
        int p = 0;
        int pp = 0;
        for (const auto &num: nums) {
            int curr = max(num + pp, p);
            pp = p;
            p = curr;
        }
        return p;
    }
};

// dp
// time: O(n)
// space: O(1)

