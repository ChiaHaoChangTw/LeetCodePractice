class Solution {
public:
    int majorityElement(vector<int>& nums) {
        return majorityElement(nums, 0, nums.size() - 1);
    }

private:
    int majorityElement(vector<int>& nums, int l, int r) {
        if (l == r) {
            return nums[l];
        }
        
        int mid = (r - l) / 2 + l;
        int leftResult = majorityElement(nums, l, mid);
        int rightResult = majorityElement(nums, mid + 1, r);
        if (leftResult == rightResult) {
            return leftResult;
        }

        int leftCount = countElement(nums, l, r, leftResult);
        int rightCount = countElement(nums, l, r, rightResult);

        return leftCount > rightCount ? leftResult : rightResult;
    }

    int countElement(vector<int>& nums, int l, int r, int target) {
        int count = 0;
        for (int i = l; i <= r; ++i) {
            if (target == nums[i]) {
                ++count;
            }
        }
        return count;
    }
};

// divide and conquer
// time O(n log n)
// space O(log n)

// sorting
// time O(n log n)
// space O(log n)
/*
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};
*/

// bit manipulation
// time O(n log C)
// space O(1)
/*
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int result = 0;

        for (int i = 0; i < 32; ++i) {
            int bit = 1 << i;
            int bitCount = 0;
            for (auto num: nums) {
                if ((bit & num) != 0) {
                    ++bitCount;
                }
            }
            if (bitCount > nums.size() / 2) {
                result |= bit;
            }
        }

        return result;
    }
};
*/

// Boyer-Moore
// time O(n)
// space O(1)
/*
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0];
        int vote = 0;
        for (auto num: nums) {
            if (vote == 0) {
                candidate = num;
            }
            if (num == candidate) {
                ++vote;
            } else {
                --vote;
            }
        }
        return candidate;
    }
};
*/

