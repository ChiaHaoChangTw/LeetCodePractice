class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> errors;
        vector<bool> visited(nums.size() + 1, false);
        int currSum = 0;
        for (const auto &num: nums) {
            if (visited[num]) {
                errors.push_back(num);
            } else {
                currSum += num;
                visited[num] = true;
            }
        }
        errors.push_back(((1 + nums.size()) * nums.size()) / 2 - currSum);
        return errors;
    }
};
