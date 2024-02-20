// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//         int n = nums.size();
//         return n * (n + 1) / 2 - reduce(nums.begin(), nums.end());
//     }
// };

// math
// time: O(n)
// space: O(1)

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int num = nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            num ^= (i ^ nums[i]);
        }
        return num;
    }
};

// XOR
// time: O(n)
// space: O(1)

