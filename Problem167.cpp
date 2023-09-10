class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size() - 1;
        while (l < r) {
            int curr = numbers[l] + numbers[r];
            if (target == curr) {
                return {l + 1, r + 1};
            } else if (target > curr) {
                ++l;
            } else {
                --r;
            }
        }
        return {0, 0};
    }
};

// 2 pointers
// time O(n)
// space O(1)

