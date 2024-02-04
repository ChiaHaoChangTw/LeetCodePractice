class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> pivotNums(nums.size(), 0);
        int smaller = 0;
        int same = 0;
        int greater = 0;
        for (const auto &num: nums) {
            if (num < pivot) {
                ++smaller;
            } else if (num == pivot) {
                ++same;
            }
        }
        greater = same + smaller;
        same = smaller;
        smaller = 0;
        for (const auto &num: nums) {
            if (num < pivot) {
                pivotNums[smaller++] = num;
            } else if (num == pivot) {
                pivotNums[same++] = num;
            } else if (num > pivot) {
                pivotNums[greater++] = num;
            }
        }
        return pivotNums;
    }
};

// 3 pointers
// time: O(n)
// space: O(1)

