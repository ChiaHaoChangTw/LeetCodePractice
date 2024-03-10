// class Solution {
// public:
//     int getCommon(vector<int>& nums1, vector<int>& nums2) {
//         int i = 0;
//         int j = 0;
//         while (i < nums1.size() && j < nums2.size()) {
//             if (nums1[i] > nums2[j]) {
//                 ++j;
//             } else if (nums1[i] < nums2[j]) {
//                 ++i;
//             } else {
//                 return nums1[i];
//             }
//         }
//         return -1;
//     }
// };

// 2 pointers
// time: O(n + m)
// space: O(1)

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return getCommon(nums2, nums1);
        }
        for (const auto &num1: nums1) {
            auto ptr = lower_bound(nums2.begin(), nums2.end(), num1);
            if (ptr != nums2.end() && *ptr == num1) {
                return num1;
            }
        }
        return -1;
    }
};

// binary search
// time: O(n log m)
// space: O(1)

