class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int result = INT_MIN;
        int currMax = 1;
        int currMin = 1;

        for (auto &num: nums) {
            int tempMax = currMax;
            int tempMin = currMin;
            currMax = (num >= 0) ? tempMax * num : tempMin * num;
            currMin = (num >= 0) ? tempMin * num : tempMax * num;
            currMax = max(currMax, num);
            currMin = min(currMin, num);
            result = max(result, currMax);
        }

        return result;
    }
};

// dp
// time O(n)
// space O(1)

