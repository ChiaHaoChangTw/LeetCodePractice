class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        int mid = 0;
        while (l <= r) {
            mid = l + (r - l) / 2;
            int midVal = nums[mid];
            int leftVal = (mid - 1 >= 0) ? nums[mid - 1] : INT_MIN;
            int rightVal = (mid + 1 < nums.size()) ? nums[mid + 1] : INT_MIN;
            if (midVal >= leftVal && midVal >= rightVal) {
                break;
            } else if (midVal < leftVal) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return mid;
    }
};

// binary search
// time O(log n)
// space O(1)

