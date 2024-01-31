class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> kStk;
        vector<int> minVec(nums.size(), INT_MAX);
        minVec[0]= nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            minVec[i] = min(nums[i], minVec[i - 1]);
        }
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (nums[i] <= minVec[i]) {
                continue;
            }
            while (!kStk.empty() && kStk.top() <= minVec[i]) {
                kStk.pop();
            }
            if (!kStk.empty() && kStk.top() < nums[i]) {
                return true;
            }
            kStk.push(nums[i]);
        }
        return false;
    }
};

// stack
// time: O(n)
// space: O(n)

